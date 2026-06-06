#ifndef CDD_FVM_H
#define CDD_FVM_H
#include "Rte_Type.h"
#include "SecOC_Prv.h"
#include "Std_Types.h"
#include "Compiler.h"
#include "Dem_Cfg_EventId.h"

#define DemEvent_D0C568          DemConf_DemEventParameter_DTC_0xd0c568_Event
#define TRIP_COUNTER_OFFSET              256
#define TRIP_COUNTER_SIZE                4
#define SECOC_OVERRIDE_FLAG_OFFSET       (TRIP_COUNTER_OFFSET + TRIP_COUNTER_SIZE)
#define SECOC_OVERRIDE_SIZE              (1)

#define SECOC_VERIFICATION_FAIL_LIMIT   255

#define FVM_SYNC_COUNTER_CONNECT(trip, reset) ((((uint64)trip) << 16) |  reset)
#define FVM_CONTRUCT_FV(trip, reset, message_cnt, rst_flag) ((((uint64)trip) << 32) | (((uint64)reset) << 16) | (message_cnt << 2) | rst_flag)
#define SWAP_U64(a)     ((a & 0xFF00000000000000) >> 56 | (a & 0x00FF000000000000) >> 40 | (a & 0x0000FF0000000000) >> 24\
                        | (a & 0x000000FF00000000) >> 8 | (a & 0x00000000FF000000) << 8 | (a & 0x0000000000FF0000) << 24\
                        | (a & 0x000000000000FF00) << 40 | (a & 0x000000000000FF) << 56)


typedef enum
{
    no_offset = 0,
    add_one,
    minus_one,
    add_two,
    minus_two
}comp_offset_type;

typedef struct
{
    uint8 failed_cnt;
    uint16 fvid;
    uint16 previous_sync_rstcnt;
    uint32 previous_sync_tripcnt;
    uint16 construct_sync_rstcnt;
    uint32 construct_sync_tripcnt;
    uint32 message_cnt;
    uint32 last_message_cnt;
    uint16 authVerifyAttempts;
}FVM_Rx_Pdu_tst;

typedef struct
{
    uint16 fvid;
    uint16 previous_sync_rstcnt;
    uint32 previous_sync_tripcnt;
    uint32 message_cnt;
}FVM_Tx_Pdu_tst;


typedef struct
{
    uint16 lasted_sync_rstcnt; 
    uint32 lasted_sync_tripcnt;
}FVM_Sync_Cnt_tst;

extern FVM_Sync_Cnt_tst FVM_Sync_cnt_st;
Std_ReturnType NvmSecuredDataWrite(uint8* BlockAddr, uint16 BlockSize);
Std_ReturnType  NvmSIDSDataWrite(uint8* BlockAddr, uint16 BlockSize);
void SecOC_FVM_Init(void);
void Get_Trip_Reset_Counter_Clear_Acceptance_Store_Trip(uint16 sync_rstcnt, uint32 sync_tripcnt);
Std_ReturnType FVM_Deal_31_B051(uint8  dataIn1, uint8 OpStatus, uint8 * dataOut1, uint8 * ErrorCode);
Std_ReturnType FVM_Deal_2E_E567 (uint8* Data, uint8* ErrorCode);
Std_ReturnType FVM_Deal_22_E554(uint8* data);
Std_ReturnType FVM_Deal_22_E555(uint8* data);
Std_ReturnType SecOC_VerifyStatusOverride(uint16 ValueID,
                                          SecOC_OverrideStatusType overrideStatus,
                                          uint8 numberOfMessagesToOverride);
#endif
