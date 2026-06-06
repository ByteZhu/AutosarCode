#ifndef CRYPTO_H
#define CRYPTO_H

#include "Mcal_Compiler.h"
#include "Crypto_GeneralTypes.h"
#include "Dem_Cfg_EventId.h"

typedef struct 
{
    uint16 ReqKeyId;
    uint16 CfgKeyId;

}tp_SecOC_KeyId_Mapping;

//*******************************************************************************************************
//Dcm_MainFunction 函数的调用周期定义
#define DcmMainFunc_Cycle        1        

//Device_key 填充不全为0故障，请将其定义为 "Dem_Cfg_EventId.h"下的EventId。如：DemConf_DemEventParameter_Event_D0C451
#define DemEvent_D0C451          DemConf_DemEventParameter_DTC_0xd0c451_Event           

//将对应2E服务的参数传递给此函数，并将其返回值作为2E服务的返回值。
extern Std_ReturnType DeviceKey_Deal_2E_D0E9 (uint8* Data, uint8* ErrorCode);   
extern Std_ReturnType SecOCKey_Deal_2E_C05D (uint8* Data, uint8* ErrorCode);
//将对应31服务的参数传递给此函数，并将其返回值作为31服务的返回值。
extern Std_ReturnType SysKeyTest_Deal_31_B050(uint8  dataIn1, uint8 OpStatus, uint8 * dataOut1, uint8 * ErrorCode);
//周期调用检测SECOC的KEY是否存在默认KEY，并报故障码
extern void SecOC_DefaultKey_CheckRoutine(void);




//*******************************************************************************************************
void Crypto_Init(void);
//NVM_MainFunction/MemIf_Rb_MainFunction 不可重入，多核或多任务调用会有TRAP及未知风险。建议封装后调用
Std_ReturnType Cdd_SafeNVM_MainFunction(void);

#endif
