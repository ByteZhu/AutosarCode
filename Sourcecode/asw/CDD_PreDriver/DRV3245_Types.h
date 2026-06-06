/* BEGIN_FILE_HDR
**************************************************************************
* NOTICE
* This software is the property of XiangBin Electric. Any information contained in this
* doc should not be reproduced, or used, or disclosed without the written authorization from
* XiangBin Electric.
**************************************************************************
* File Name: DRV32345_Types.h
********************************************************************
* Project/Product: EPS
* Title: DRV3245棰勯┍鑺墖椹卞姩
* Author: LHC
*********************************************************************
* Description:
*	姝ゆ枃浠剁敤浜庡畾涔塂RV3245瀵勫瓨鍣ㄧ粨鏋勪綋
*
* (Requirements, pseudo code and etc.)
*********************************************************************
* Limitations:
* 	鏈枃浠朵粎閫傜敤浜庢惌杞紻RV3245鑺墖鐨勬帶鍒跺櫒
* (limitations)
*********************************************************************
*********************************************************************
* Revision History锛�
*
* Version      Date         Author             Descriptions
* ----------    --------------    ------------   ----------------------------------------
* 1.0       		2024-05-22      	LHC            Original
*
********************************************************************
*END_FILE_HDR */
#ifndef _DRV3245_TYPES_H_
#define _DRV3245_TYPES_H_

#include "Std_Types.h"

#define DRV3245_SPI_WRITE (0)
#define DRV3245_SPI_READ (1)

typedef enum
{
    DRV3245_IC_STAT0 = 0x01,// Read only
    DRV3245_OV_VDS_FAULT = 0x02,// Read only
    DRV3245_IC_FAULT = 0x03,// Read only
    DRV3245_VGS_FAULT = 0x04,// Read only
    DRV3245_HS_GATE_DRIVE_CTRL = 0x05,
    DRV3245_LS_GATE_DRIVE_CTRL = 0x06,
    DRV3245_GATE_DRIVE_CTRL = 0x07,
    DRV3245_IC_OPERATION = 0x09,
    DRV3245_SHUNT_AMPLIDIER_CTRL = 0x0A,
    DRV3245_SHUNT_AMPLIDIER_CTRL_EXTRAL = 0x00,
    DRV3245_IC_CTRL0 = 0x0A,
    DRV3245_IC_CTRL0_EXTRAL = 0x01,
    DRV3245_IC_CTRL1 = 0x0A,
    DRV3245_IC_CTRL1_EXTRAL = 0x02,
    DRV3245_PHC_CTRL = 0x0A,
    DRV3245_PHC_CTRL_EXTRAL = 0x04,
    DRV3245_PHC_STAT = 0x0A,// Read only
    DRV3245_PHC_STAT_EXTRAL = 0x05,
    DRV3245_VOLTAGE_REGULATOR_CTRL = 0x0B,
    DRV3245_VDS_SENSE_CTRL0 = 0x0C,
    DRV3245_VDS_SENSE_CTRL0_EXTRAL = 0x00,
    DRV3245_VDS_SENSE_CTRL1 = 0x0C,
    DRV3245_VDS_SENSE_CTRL1_EXTRAL = 0x01,
    DRV3245_VDS_SENSE_CTRL2 = 0x0C,
    DRV3245_VDS_SENSE_CTRL2_EXTRAL = 0x02,
    DRV3245_VGS_CTRL1 = 0x0C,
    DRV3245_VGS_CTRL1_EXTRAL = 0x04,
    DRV3245_SPI_TEST = 0x0D,
    DRV3245_SPI_TEST_EXTRAL = 0x00,
    DRV3245_SPIWR_CRC = 0x0D,
    DRV3245_SPIWR_CRC_EXTRAL = 0x01,
    DRV3245_SPIRD_CRC = 0x0D,
    DRV3245_SPIRD_CRC_EXTRAL = 0x02,
    DRV3245_IC_STAT1 = 0x0D,// Read only
    DRV3245_IC_STAT1_EXTRAL = 0x03,
    DRV3245_IC_STAT2 = 0x0D,// Read only
    DRV3245_IC_STAT2_EXTRAL = 0x04,
    DRV3245_NO_EXTRAL = 0x00,
} DRV3245_RegAddrType;

typedef union {
  struct
  {
    uint16 DATA_WRTIE : 11;
    uint16 ADDRESS : 4;
    uint16 RW : 1;
  } write_bits;

  struct
  {
    uint16 RSV : 8;
    uint16 ADDRESS_EXTRAL : 3;
    uint16 ADDRESS : 4;
    uint16 RW : 1;
  } read_bits;

  uint16 data;
} DRV3245_TxDataType;

typedef union {
  struct
  {
    uint16 DATA_READ : 11;
    uint16 RSV : 5;
  } bits;
  uint16 data;
} DRV3245_RxDataType;

typedef union {
  struct
  {
    uint16 OTW : 1;
    uint16 SPI_OK : 1;
    uint16 BIST_STAT : 1;
    uint16 DRV_STAT : 1;
    uint16 RSV1 : 1;
    uint16 VDS_STAT : 1;
    uint16 PVDD_OVFL : 1;
    uint16 PVDD_UVFL : 1;
    uint16 RSV2 : 2;
    uint16 FAULT : 1;
    uint16 RSV3 : 5;
  } bits;
  uint16 data;
} DRV3245_IC_STAT0Type;

typedef union {
  struct
  {
    uint16 SNS_A_OCP : 1;
    uint16 SNS_B_OCP : 1;
    uint16 SNS_C_OCP : 1;
    uint16 RSV1 : 2;
    uint16 VDS_LC : 1;
    uint16 VDS_HC : 1;
    uint16 VDS_LB : 1;
    uint16 VDS_HB : 1;
    uint16 VDS_LA : 1;
    uint16 VDS_HA : 1;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_OV_VDS_FAULTType;

typedef union {
  struct
  {
    uint16 VCPH_OVLO_ABS : 1;
    uint16 VCPH_OVLO : 1;
    uint16 VCPH_UVLO : 1;
    uint16 VCP_LSD_OVLO : 1;
    uint16 VCP_LSD_UVLO : 1;
    uint16 AVDD_UVLO : 1;
    uint16 AVDD_OVLO : 1;
    uint16 DVDD_OVLO : 1;
    uint16 RSV1 : 2;
    uint16 PVDD_UVLO : 1;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_IC_FAULTType;

typedef union {
  struct
  {
    uint16 RSV1 : 5;
    uint16 VGS_LC : 1;
    uint16 VGS_HC : 1;
    uint16 VGS_LB : 1;
    uint16 VGS_HB : 1;
    uint16 VGS_LA : 1;
    uint16 VGS_HA : 1;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_VGS_FAULTType;

typedef union {
  struct
  {
    /*
    High-side gate driver peak source current
    "00" = 0.05A
    "01" = 0.25A
    "10" = 0.75A
    "11" = 1.0A
    */
    uint16 IDRIVEP_HS : 2;
    uint16 RSV1 : 2;
    /*
    High-side gate driver peak sink current
    "00" = 0.25A
    "01" = 0.25A
    "10" = 0.75A
    "11" = 1.0A
    */
    uint16 IDRIVEN_HS : 2;
    uint16 RSV2 : 2;
    /*
    High-side and low-side gate driver peak sink time
    "00" = 220ns
    "01" = 440ns
    "10" = 880ns
    "11" = 1780ns
    */
    uint16 TDRIVEN : 2;
    uint16 RSV3 : 6;
  } bits;
  uint16 data;
} DRV3245_HS_GATE_DRIVE_CTRLType;

typedef union {
  struct
  {
    /*
    Low-side gate driver peak source current
    "00" = 0.05A
    "01" = 0.25A
    "10" = 0.75A
    "11" = 1.0A
    */
    uint16 IDRIVEP_LS : 2;
    uint16 RSV1 : 2;
    /*
    Low-side gate driver peak sink current
    "00" = 0.25A
    "01" = 0.25A
    "10" = 0.75A
    "11" = 1.0A
    */
    uint16 IDRIVEN_LS : 2;
    uint16 RSV2 : 2;
    /*
    High-side and low-side gate driver peak source time
    "00" = 220ns
    "01" = 440ns
    "10" = 880ns
    "11" = 1780ns
    */
    uint16 TDRIVEP : 2;
    /*
    "0" = Normal TDRIVEP and IHOLD operation. The gate 
          driver sink current is the IHOLD current after the tDRIVEP time.
    "1" = Regardless of the TDRIVEP register bit setting, 
          the gate-driver sink current does not move to the IHOLD current 
          but keeps the driver current specified by the IDRIVEP_HS and IDRIVEP_LS bits.
    */
    uint16 IHOLD_MODE : 1;
    uint16 RSV3 : 5;
  } bits;
  uint16 data;
} DRV3245_LS_GATE_DRIVE_CTRLType;

typedef union {
  struct
  {
    /*
    VDS sense deglitch time
    "00" = 5us
    "01" = 1.75us
    "10" = 3.5us
    "11" = 7us
    */
    uint16 TVDS : 2;
    /*
    VDS sense blanking time
    "00" = 0us
    "01" = 1.75us
    "10" = 3.5us
    "11" = 7us
    */
    uint16 TBLANK : 2;
    /*
    Predriver input dead time
    "000" = 150ns
    "001" = 298ns
    "010" = 439ns
    "011" = 579ns
    "100" = 895ns
    "101" = 1772ns
    "110" = 3526ns
    "111" = 5281ns
    */
    uint16 DEAD_TIME : 3;
    /*
    PWM mode
    "00" = 6-PWM mode. PWM with 6 independent inputs
    "01" = 3-PWM mode. PWM with 3 independent inputs
    "10" = 1-PWM mode. PWM with one input
    "11" = 6-PWM mode. PWM with 6 independent inputs
    */
    uint16 PWM_MODE : 2;
    /*
    1 PWM mode control
    "0" = 1-PWM mode uses synchronous rectification
    "1" = 1-PWM mode uses asyncrhonous rectification (diode freewheeling)
    */
    uint16 PWM_COM : 1;
    /*
    Enable predriver bit
    "0" = Predriver is disabled and in the Passive Pulldown mode.
    "1" = Predriver is active pullup or pull-down controlled by INH and INL digital inputs.
    */
    uint16 ENABLE_DRV : 1;
    uint16 RSV1 : 5;
  } bits;
  uint16 data;
} DRV3245_GATE_DRIVE_CTRLType;

typedef union {
  struct
  {
    uint16 RSV1 : 1;
    /*
    Clear faults
    "0" = Normal operation
    "1" = Clear faults
    */
    uint16 CLR_FLTS : 1;
    /*
    PVDD overvoltage fault reporting mode
    "0" = Warning. No gate driver shutdown
    "1" = Fault. Gate Driver shutdown
    */
    uint16 PVDD_OV_MODE : 1;
    uint16 RSV2 : 1;
    /*
    Disable SNS overcurrent protection fault and reporting
    "0" = SNS OCP enabled
    "1" = SNS OCP disabled
    */
    uint16 DIS_SNS_OCP : 1;
    /*
    Dead-time protection mode in the 3-PWM and 1-PWM modes
    "00" =  Dead-time protection is enabled. The gate driver outputs 
            are forced low during the dead time period. The SPI fault flag 
            is set and the nFAULT pin is driven low when the dead time 
            condition is detected.
    "11" =  Dead-time protection is enabled. The gate driver outputs 
            are forced low during the dead time period. The SPI fault flag 
            is set and the nFAULT pin is driven low when the dead time 
            condition is detected.
    "01" =  Dead-time protection is enabled but no reporting is 
            performed. The gate driver outputs are forced low during the 
            dead time period. The SPI fault flag is never set and the nFAULT 
            pin stays high when the dead time condition is detected
    "10" =  Dead-time protection is disabled. No dead time is 
            inserted. No SPI fault flag is set and the nFAULT pin stays high
    */
    uint16 DEADT_MODE : 2;
    /*
    Shoot-through protection report mode
    "0" = Shoot-through protection is enabled. The gate driver 
          outputs are forced low during a shoot-through condition. The 
          SPI fault flag is set and the nFAULT pin is driven low when the 
          condition is detected.
    "1" = Shoot-through protection is enabled but no reporting 
          is performed. The gate driver outputs are forced low during 
          a shoot-through condition. No SPI fault flag is set, and the 
          nFAULT pin stays high when the condition is detected.
    */
    uint16 STP_MODE : 1;
    /*
    VGS detection mode
    "00" =  VGS fault flags (VGS_xx) are set, the nFAULT pin is 
            driven low, and the gate driver is shutdown when the VGS fault 
            is detected. The ENABLE_DRV bit is cleared.
    "01" =  VGS detection is disabled. The VGS fault flags (VGS_xx) 
            are never set. Shutdown and nFAULT reporting are disabled.
    "10" =  VGS fault flags (VGS_xx) are set and nFAULT is driven 
            low when VGS fault is detected. Shutdown is disabled.
    "11" =  VGS fault flags (VGS_xx) are set when a VGS fault is 
            detected. Shutdown and nFAULT reporting are disabled
    */
    uint16 VGS_MODE : 2;
    uint16 RSV3 : 6;
  } bits;
  uint16 data;
} DRV3245_IC_OPERATIONType;

typedef union {
  struct
  {
    /*
    Gain of CS amplifier 1
    "00" = 10 V/V
    "01" = 20 V/V
    "10" = 40 V/V
    "11" = 80 V/V
    */
    uint16 GAIN_CS1 : 2;
    /*
    Gain of CS amplifier 2
    "00" = 10 V/V
    "01" = 20 V/V
    "10" = 40 V/V
    "11" = 80 V/V
    */
    uint16 GAIN_CS2 : 2;
    /*
    Gain of CS amplifier 3
    "00" = 10 V/V
    "01" = 20 V/V
    "10" = 40 V/V
    "11" = 80 V/V
    */
    uint16 GAIN_CS3 : 2;
    /*
    CSA2 (SO2) diagnostic mode
    "0" = Normal mode
    "1" = Sense amplifier is disabled and the SO2 output is in the 
          Hi-Z state. The SO2 output is pulled up to the VREF pin.
    */
    uint16 CSA2_DIAG : 1;
    uint16 RSV1 : 1;
    /*
    000b
    */
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_SHUNT_AMPLIDIER_CRTLType;

typedef union {
  struct
  {
    /*
    Warning reporting mode (nFAULT) for the PVDD_OVFL and VDS_xx bits.
    "0" = No warning error is reported on the nFAULT pin. The SPI flags are set
    "1" = A warning error is reported on the nFAULT pin by driving the pin low
    */
    uint16 WARN_MODE : 1;
    /*
    Configuration data CRC enable
    "0" = Stops periodic configuration-data CRC check
    "1" = Starts periodic (approximately 1 ms) configuration-data CRC check
    */
    uint16 CFG_CRC_EN : 1;
    /*
    Predriver shutdown current IDRIVESHD control
    "00" = 0.25 A
    "01" = 0.25 A
    "10" = 0.75 A
    "11" = 1.0 A
    */
    uint16 IDRIVESD : 2;
    uint16 RSV1 : 4;
    /*
    001b
    */
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_IC_CRTL0Type;

typedef union {
  struct
  {
    /*
    Configuration data CRC diagnostic mode
    "0" = No action
    "1" = Configuration data CRC runs one time without a 1-ms 
          timer. The MCU waits 10 碌s to read the CFG_CRC_FAULT flag 
          after the MCU sets the CFG_CRC_DIAG bit. This bit can be 
          used to diagnose the configuration data CRC function.
    */
    uint16 CFG_CRC_DIAG : 1;
    /*
    Driver SHx pin diagnostic mode
    "0" = No action
    "1" = Charge pump is disabled and the gate drivers are put into 
          sleep mode, where both the pullup and pull-down of the gate 
          driver are disabled. The SHS pin has minimum leakage current 
          in this mode. nFAULT is driven low.
    */
    uint16 DRV_SH_DIAG : 1;
    /*
    DRVOFF VGS diagnostic mode
    "0" = VGS monitor is disabled and TDRIVESD control is valid 
          when the DRVOFF pin is driven high.
    "1" = VGS monitor is not affected by the DRVOFF pin. 
          TDRIVESD control is not executed, and the gate driver directly 
          moves to the passive pull down state.
    */
    uint16 DRVOFF_DIAG : 1;
    uint16 RSV1 : 5;
    /*
    010b
    */
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_IC_CRTL1Type;

typedef union {
  struct
  {
    /*  
    Phase comparator enable (A, B, C devices only)
    "0" = PHCx comparators are disabled.
    "1" = PHCx comparators are enabled.
    */
    uint16 PHC_COMP_EN : 1;
    /*  
    Phase-comparator output enable (B device only)
    "0" = Disable. PHCA, PHCB, and PHCC are driven low all the time.
    "1" = PHCA, PHCB, and PHCC output buffers are activated.
    */
    uint16 PHC_OUTEN : 1;
    /*  
    Phase-comparator threshold mode (A, B, C devices only)
    "0" = 75% or 25%
    "1" = 50%
    */
    uint16 PHC_MODE : 1;
    uint16 RSV1 : 5;
    /*
    100b
    */
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_PHC_CRTLType;

typedef union {
  struct
  {
    uint16 PHCACOMP : 1;
    uint16 PHCBCOMP : 1;
    uint16 PHCCCOMP : 1;
    uint16 RSV1 : 5;
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_PHC_STATType;

typedef union {
  struct
  {
    /*  
    Charge pump shutdown mode
    "0" = The charge pump stays active if a VCPH_UVLO, 
          VCP_LSD_UVLO, or VGS gate-source voltage fault condition 
          is detected.
    "1" = The charge pump is disabled if a VCPH_UVLO, 
          VCP_LSD_UVLO, or VGS gate-source voltage fault condition 
          is detected
    */
    uint16 CP_SD_MODE : 1;
    /*  
    Charge pump disable
    "0" =  No action. Charge pump is enabled unless an internal fault 
           is detected.
    "1" = Charge pump is disabled. No impact to nFAULT output.
    */
    uint16 CP_DIS : 1;
    /*  
    VCPH_OV_ABS fault mode
    "0" =  Warning. No gate driver shutdown
    "1" =  Fault. Gate driver shutdown
    */
    uint16 VCPHOVABS_MODE : 1;
    uint16 RSV1 : 5;
    /*
    VREF scaling
    "00" = k=2
    "01" = k=2
    "10" = k=4
    "11" = k=8
    */
    uint16 VREF_SCALE : 2;
    uint16 RSV2 : 6;
  } bits;
  uint16 data;
} DRV3245_VOLTAGE_REGULATOR_CTRLType;

typedef union {
  struct
  {
    /*
    VDS mode
    "000" = Latched shut down when an overcurrent event is 
            detected. The nFAULT pin is driven low and the predriver is shut 
            down. The ENABLE_DRV bit is cleared.
    "001" = Report-only when an overcurrent event is detected. The 
            nFAULT pin reporting is enabled by the WARN_MODE bit.
            010b = VDS protection disabled (no overcurrent sensing or 
            reporting)
    */
    uint16 VDS_MODE : 3;
    /*  
    VDS diagnostic mode
    "0" =  Normal mode. The VDS comparator threshold is 
           determined by the VDS_LEVEL register bit.
    "1" =  VDS comparators of all high-side and low-side channels 
           are in the diagnostic mode. The VDS comparator threshold is 
           鈥�0.2 V regardless of the VDS_LEVEL setting
    */
    uint16 VDS_DIAG : 1;
    /*
    Predriver shutdown current IDRIVESHD control
    "0000" = 0.1V
    "0001" = 0.15V
    "0010" = 0.2V
    "0011" = 0.25V
    "0100" = 0.3V
    "0101" = 0.35V
    "0110" = 0.4V
    "0111" = 0.45V
    "1000" = 0.5V
    "1001" = 0.6V
    "1010" = 0.7V
    "1011" = 0.8V
    "1100" = 0.9V
    "1101" = 1.0V
    "1110" = 2.0V
    "1111" = 2.0V
    */
    uint16 VDS_LEVEL : 4;
    /*
    000b
    */
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_VDS_SENSE_CTRL0Type;

typedef union {
  struct
  {
    /*  
    VDS diagnostic mode
    "0" =  The VDS_LEVEL bit is used for all high-side and low-side 
           VDS comparators
    "1" =  The VDS_LEVEL bit is used for the low-side VDS 
           comparator. The VDS_LEVEL_HS_x (where x is A, B, or C) bits 
           are used for the high-side VDS comparators.
    */
    uint16 VDS_CFG_MODE : 1;
    uint16 RSV1 : 3;
    /*
    VDS comparator threshold for high-side channel A
    "0000" = 0.1V
    "0001" = 0.15V
    "0010" = 0.2V
    "0011" = 0.25V
    "0100" = 0.3V
    "0101" = 0.35V
    "0110" = 0.4V
    "0111" = 0.45V
    "1000" = 0.5V
    "1001" = 0.6V
    "1010" = 0.7V
    "1011" = 0.8V
    "1100" = 0.9V
    "1101" = 1.0V
    "1110" = 2.0V
    "1111" = 2.0V
    */
    uint16 VDS_LEVEL_HSA : 4;
    /*
    001b
    */
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_VDS_SENSE_CTRL1Type;

typedef union {
  struct
  {
    /*
    VDS comparator threshold for high-side channel C
    "0000" = 0.1V
    "0001" = 0.15V
    "0010" = 0.2V
    "0011" = 0.25V
    "0100" = 0.3V
    "0101" = 0.35V
    "0110" = 0.4V
    "0111" = 0.45V
    "1000" = 0.5V
    "1001" = 0.6V
    "1010" = 0.7V
    "1011" = 0.8V
    "1100" = 0.9V
    "1101" = 1.0V
    "1110" = 2.0V
    "1111" = 2.0V
    */
    uint16 VDS_LEVEL_HSC : 4;
    /*
    VDS comparator threshold for high-side channel B
    "0000" = 0.1V
    "0001" = 0.15V
    "0010" = 0.2V
    "0011" = 0.25V
    "0100" = 0.3V
    "0101" = 0.35V
    "0110" = 0.4V
    "0111" = 0.45V
    "1000" = 0.5V
    "1001" = 0.6V
    "1010" = 0.7V
    "1011" = 0.8V
    "1100" = 0.9V
    "1101" = 1.0V
    "1110" = 2.0V
    "1111" = 2.0V
    */
    uint16 VDS_LEVEL_HSB : 4;
    /*
    010b
    */
    uint16 EXTRA_ADDR : 3;
    uint16 RSV1 : 5;
  } bits;
  uint16 data;
} DRV3245_VDS_SENSE_CTRL2Type;

typedef union {
  struct
  {
    /*
    VGS detection blanking time
    "00" = 2.5 碌s
    "01" = 3.0 碌s
    "10" = 5.0 碌s
    "11" = 7.1 碌s
    */
    uint16 VGS_BLANK : 2;
    /*
    VGS detection deglitch time
    "00" = 0.5 碌s
    "01" = 0.9 碌s
    "10" = 1.5 碌s
    "11" = 2.0 碌s
    */
    uint16 VGS_DEG : 2;
    /*  
    VGS detection threshold mode
    "0" =   2 level threshold mode. The VVGS_TRIP_L threshold is used 
            when the INH or INL pin is low and the VVGS_TRIP_H threshold is 
            used when the INHor INL pin is Hhigh
    "1" =   1 level threshold mode. The VVGS_TRIP_L threshold is used 
            in both cases when the INH or INL pin is low and the INH or INL 
            pin is high
    */
    uint16 VGS_TH_MODE : 1;
    uint16 RSV1 : 3;
    /*
    100b
    */
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_VGS_CTRL1Type;

typedef union {
  struct
  {
    uint16 SPI_TEST : 8;
    uint16 EXTRA_ADDR : 3;
    uint16 RSV1 : 5;
  } bits;
  uint16 data;
} DRV3245_SPI_TESTType;

typedef union {
  struct
  {
    uint16 SPIWR_CRC : 8;
    uint16 EXTRA_ADDR : 3;
    uint16 RSV1 : 5;
  } bits;
  uint16 data;
} DRV3245_SPIWR_CRCType;

typedef union {
  struct
  {
    uint16 SPIRD_CRC : 8;
    uint16 EXTRA_ADDR : 3;
    uint16 RSV1 : 5;
  } bits;
  uint16 data;
} DRV3245_SPIRD_CRCType;

typedef union {
  struct
  {
    uint16 CLK_MON_FAULT : 1;
    uint16 CFG_CRC_FAULT : 1;
    uint16 INT_REG_FAULT : 1;
    uint16 DEADT_FAULT : 1;
    uint16 STP_FAULT : 1;
    uint16 RSV1 : 3;
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_IC_STAT1Type;

typedef union {
  struct
  {
    uint16 DEV_MODE_FAULT : 1;
    uint16 ABIST_FAULT : 1;
    uint16 CLKMON_BIST_FAULT : 1;
    uint16 EE_CRC_FAULT : 1;
    uint16 SPI_CLK_FAULT : 1;
    uint16 SPI_ADDR_FAULT : 1;
    uint16 SPIWR_CRC_FAULT : 1;
    uint16 RSV1 : 1;
    uint16 EXTRA_ADDR : 3;
    uint16 RSV2 : 5;
  } bits;
  uint16 data;
} DRV3245_IC_STAT2Type;


#endif
