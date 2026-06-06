/*
 * EepromData.h
 *
 *  Created on: 2019-2-20
 *      Author: TIAN
 */

#ifndef EEPROMDATA_H_
#define EEPROMDATA_H_

#include "Common.h"

typedef union
{
	uint8 byte[16];
	uint16 halfword[8];
	struct
	{
		UInt16 i[3];
		UInt16 rsv;//resolver sin&cos gain
		UInt8  bat;//battery voltage difference
		UInt8  nmt;//normal temperature
		UInt8  ic[3];
		UInt8  hgt;//high temperature
		UInt8  rfu;
		UInt8  crc;
	}data;
}Eeprom_CalibGainOffsType;

typedef union
{
	uint8 byte[8];
	uint16 halfword[4];
	struct
	{
		UInt16 a0;
		UInt16 al;
		UInt16 ar;
		UInt8  st;
		UInt8  crc;
	}data;
}Eeprom_CalibAngleType;

typedef union
{
	uint8 byte[8];
	sint16 halfword[4];
	struct
	{
		sint16 sinmax;
		sint16 sinmin;
		sint16 cosmax;
		sint16 cosmin;
	}data;
}Eeprom_MotorResolverType;

typedef union
{
	uint8 byte[8];
	sint16 halfword[4];
	struct
	{
		sint16 phasesinmax;
		sint16 phasesinmin;
		sint16 phasecosmax;
		sint16 phasecosmin;
	}data;
}Eeprom_MotorPhaseType;

typedef union
{
	uint8 byte[8];
	uint16 halfword[4];
	sint32 word[2];
	struct
	{
		sint32 intialangle;
		sint16 anglecorrect;
		uint16 crc;
	}data;
}Eeprom_MotorAngleType;

typedef union
{
	uint8 byte[8];
	uint16 halfword[4];
	struct
	{
		UInt16 a0crr;
		UInt16 rtrofs;
		UInt8  rfu[3];
		UInt8  crc;
	}data;
}Eeprom_CalibAngleCorrectType;

typedef union
{
	UInt8  byte[14];
	struct
	{
		UInt8  BatVol;  //*0.1  [0, 25.5][V]
		UInt8  HW_Torque;//*0.1 [-12.7, 12.8][Nm]
		UInt16 HW_Angle;//*0.1 [-3276.7, 3276.7][Deg]
		UInt8  EnglineSpeed; // *40 [0, 8160][RPM]
		UInt8  VehicleSpeed;//1 [0, 255][km/h]
		UInt8  Feedback_Motor_Current;//1 [-127, 128][A]
		UInt8  resver1;
		UInt8  resver2;
		UInt8  resver3;
		UInt8  resver4;
		UInt8  resver5;
		UInt8  checksum;
		UInt8  OccurCnt;//1
	}data;
}Eeprom_Slow0DataType;

typedef union
{
	uint8 byte[8];
	struct
	{
		uint32 mileage;
		UInt32  crc;
	}data;
}Eeprom_MileageType;

typedef union
{
	uint8 byte[32];
	struct
	{
		uint16 ccp142;
		uint8 ccp1;
		uint8 ccp3;
		uint8 ccp13;
		uint8 ccp17;
		uint8 ccp50;
		uint8 ccp58;
		uint8 ccp59;
		uint8 ccp62;
		uint8 ccp100;
		uint8 ccp150;
		uint8 ccp317;
		uint8 ccp494;
		uint8 ccp540;
		uint8 ccp547;
		uint8 ccp565;
		uint8 ccp609;
		uint8 ccp639;
		uint8 ccp640;
		uint8 ccp655;
		uint8 ccp695;
		uint8 ccp741;
		uint8 rsv[8];
		uint8  crc;
	}data;
}Eeprom_CanCCpType;

/* Fast0 data */
extern Eeprom_CalibGainOffsType Eeprom_CalibGainOffset;
extern Eeprom_CalibGainOffsType Eeprom_CalibGainOffsetMrr;
extern uint8 Eeprom_TestMode[];
extern Eeprom_MotorResolverType Eeprom_MotorResolver;
extern Eeprom_MotorPhaseType Eeprom_MotorPhase;
extern Eeprom_MotorAngleType Eeprom_MotorAngle;
/* Fast1 data */
extern Eeprom_CalibAngleType Eeprom_CalibAngle;
extern uint8 Eeprom_CalibAngleCorrectReserve[];
extern Eeprom_CalibAngleCorrectType Eeprom_CalibAngleCorrect;
extern Eeprom_CalibAngleType Eeprom_CalibAngleMrr;
extern uint8 Eeprom_SupplierInfo[16];
extern uint8 Eeprom_VehicleName[8];
extern uint8 Eeprom_VIN[17];
extern uint8 Eeprom_SystemName[8];
extern uint8 Eeprom_RepairCode[16];
extern uint8 Eeprom_ProgramDate[4];
extern uint8 Eeprom_EcuInstallDate[8];
extern uint8 Eeprom_BackupConfig[64];
extern uint8 Eeprom_FunConfig[8];
extern uint8 Eeprom_VehicleConfig[8];
extern uint8 Eeprom_SoftwareConfig[8];
extern uint8 Eeprom_CustomInfo[144];
extern uint8 Eeprom_SpareNum[19];
/* 16 */
extern uint8 Eeprom_BatteryCode[30];
/* 17 */
extern uint8 Eeprom_Motorcode[30];
/* 18 */
extern uint8 Eeprom_AppFingerprintId[16];
/* 19 */
extern uint8 Eeprom_EOL_Config[4];
/* 20 */
extern uint8 Eeprom_SoftwareVerNumber[11];
/* 21 */
extern uint8 Eeprom_ECUSoftwareNumber[4];
//ZKT 240412
/* 22 */
extern uint8 Eeprom_EOL_Date[8];
/* 23 */
extern uint8 Eeprom_Last_After_SaleDate[8];
/* 24 */
extern uint8 Eeprom_Last_DownloadDate[8];
/* 25 */
extern uint8 Eeprom_Diagnostic_ToolIdentifier[8];
/* 26 */
extern uint8 Eeprom_Supplier0[32];
/* 27 */
extern uint8 Eeprom_Supplier1[32];
/* 28 */
extern uint8 Eeprom_Supplier2[32];
/* 29 */
extern uint8 Eeprom_control2e_once[8];

extern Eeprom_CanCCpType Eeprom_CanCCp;
/* Slow0 data */
extern Eeprom_Slow0DataType Eeprom_SnapShots[];
/* Slow1 data */
extern uint8 Eeprom_BTSignature[];
extern uint8 Eeprom_IgnitionCycle[];
extern uint8 Eeprom_DTCStatus[];
extern uint8 Eeprom_ResetFlag[];
extern Eeprom_MileageType Eeprom_Mileage;
extern uint8 Eeprom_AssitMode[8];
extern uint8 Eeprom_ExternDataRecord[16];
extern uint8 Eeprom_PINCODE[];

#endif /* EEPROMDATA_H_ */

