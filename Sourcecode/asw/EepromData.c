/*
 * Eeprom_Data.c
 *
 *  Created on: 2019-2-20
 *      Author: TIAN
 */

#include "EepromData.h"

/* Fast0 data */
/* 0 */
Eeprom_CalibGainOffsType Eeprom_CalibGainOffset = {{0,}};
/* 1 */
Eeprom_CalibGainOffsType Eeprom_CalibGainOffsetMrr = {{0,}};
/* 2 */
uint8 Eeprom_TestMode[8] = {0};
/* 3 */
Eeprom_MotorResolverType Eeprom_MotorResolver = {{0,}};
/* 4 */
Eeprom_MotorPhaseType Eeprom_MotorPhase = {{0,}};
/* 5 */
Eeprom_MotorAngleType Eeprom_MotorAngle = {{0,}};

/* Fast1 data */
/* 0 */
Eeprom_CalibAngleType Eeprom_CalibAngle = {{0,}};
/* 1 */
uint8 Eeprom_CalibAngleCorrectReserve[8] = {0};
/* 2 */
Eeprom_CalibAngleType Eeprom_CalibAngleMrr = {{0,}};
/* 3 */
uint8 Eeprom_SupplierInfo[16] = {0};
/* 4 */
uint8 Eeprom_VehicleName[8] = {0};
/* 5 */
uint8 Eeprom_VIN[17] = {0};
/* 6 */
uint8 Eeprom_SystemName[8] = {0};
/* 7 */
uint8 Eeprom_RepairCode[16] = {0};
/* 8 */
uint8 Eeprom_ProgramDate[4] = {0};
/* 9 */
uint8 Eeprom_EcuInstallDate[8] = {0};
/* 10 */
uint8 Eeprom_BackupConfig[64] = {0};
/* 11 */
uint8 Eeprom_FunConfig[8] = {0};
/* 12 */
uint8 Eeprom_VehicleConfig[8] = {0};
/* 13 */
uint8 Eeprom_SoftwareConfig[8] = {0};
/* 14 */
uint8 Eeprom_CustomInfo[144] = {0};
/* 15 */
uint8 Eeprom_SpareNum[19] = {0};
/* 16 */
uint8 Eeprom_BatteryCode[30] = {0};
/* 17 */
uint8 Eeprom_Motorcode[30] = {0};
/* 18 */
uint8 Eeprom_AppFingerprintId[16] = {0};
/* 19 */
uint8 Eeprom_EOL_Config[4] = {0};//要求为2字节，扩充为4字节进行错误校验
/* 20 */
uint8 Eeprom_SoftwareVerNumber[11] = {0};
/* 21 */
uint8 Eeprom_ECUSoftwareNumber[4] = {0};
//ZKT
/* 22 */
uint8 Eeprom_EOL_Date[8] = {0};
/* 23 */
uint8 Eeprom_Last_After_SaleDate[8] = {0};
/* 24 */
uint8 Eeprom_Last_DownloadDate[8] = {0};
/* 25 */
uint8 Eeprom_Diagnostic_ToolIdentifier[8] = {0};
/* 26 */
uint8 Eeprom_Supplier0[32] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
/* 27 */
uint8 Eeprom_Supplier1[32] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
/* 28 */
uint8 Eeprom_Supplier2[32] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
/* 29 */
uint8 Eeprom_control2e_once[8] = {0};

Eeprom_CanCCpType Eeprom_CanCCp;



/* Slow0 data */
Eeprom_Slow0DataType Eeprom_SnapShots[128];
/* Slow1 data */
/* 0 */
uint8 Eeprom_BTSignature[8] = {0};
/* 1 */
uint8 Eeprom_IgnitionCycle[EPS_DTC_NUM_MAX] = {0};//((((EPS_DTC_NUM_MAX-1)>>3)<<3) + 8)
/* 2 */
uint8 Eeprom_DTCStatus[16] = {0};
/* 3 */
uint8 Eeprom_ResetFlag[8] = {0};
/* 4 */
Eeprom_MileageType Eeprom_Mileage;
/* 5 */
uint8 Eeprom_AssitMode[8] = {0};
/* 6 */
uint8 Eeprom_ExternDataRecord[16] = {0};

Eeprom_CalibAngleCorrectType Eeprom_CalibAngleCorrect;

uint8 Eeprom_PINCODE[24] = {0};
