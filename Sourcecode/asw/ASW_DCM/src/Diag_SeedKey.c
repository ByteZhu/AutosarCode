/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Project :    ETAS Entry Platform
 * Component:  ASW_DCM
 * Description: Testcode for ASW_DCM
 * Version         Author:       Date               Update information
 * 1.0             HAD1HC        7-Nov-2018         Create software
 * 1.1             AGT1HC        19-Nov-2021        Update the Banner
 * 1.2             HAD1HC        04-Mar-2021        Update functions for new 
 * 													DIAG requirements
 * 1.3             HAD1HC        13-Apr-2021        Update Memmap
 * 1.4             XHA3SGH       06-Aug-2021        Conifgure seed for warning removed
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************/

#include <AES1.h>
#include "Std_Types.h"
#include "rte_Type.h"
#include "rte.h"
//#include "Dcm_Lcfg_DspUds.h"
#include "dcm.h"
#include "IdsM.h"
#include "IfxStm_reg.h"
#include "AES_CMAC.h"
#include "EepromData.h"
#define SWC_COMPARE_KEY_FAILED 11

#define ASW_DCM_START_SEC_CONST_8
#include "ASW_DCM_MemMap.h"
/* Seed values for Service 0x27 */
const uint8 DcmSeed[4] = {0x10,0x20,0x30,0x40};
/* Key values for Service 0x27 */
const uint8 DcmKey_L1[4] = {0x11,0x21,0x31,0x41};

const uint8 DcmKey_L49[4] = {0x15,0x25,0x35,0x45};
static uint8 GetSeed[16]={0,};
static uint8 PrimitiveSeed[16]={0,};
#define ASW_DCM_STOP_SEC_CONST_8
#include "ASW_DCM_MemMap.h"

#define ASW_DCM_START_SEC_CODE
#include "ASW_DCM_MemMap.h"
/******************************************************************************************************************//**
 *
 *  \details Compare the src data with des data.
 *
 *  \param[out] des  - the destination address.
 *  \param[in]  src  - the source content.
 *  \param[in]  size - the size of the data.
 *
 *  \since 1.0.0
 *
 *********************************************************************************************************************/
unsigned char Bl_MemCmp(const void *des, const void *src, unsigned char size)
{
    unsigned char ret = SWC_COMPARE_KEY_FAILED;
    unsigned char i;
    const unsigned char *d = des;
    const unsigned char *s = src;

    if ((d != NULL_PTR) && (s != NULL_PTR))
    {
        ret = RTE_E_OK;
        for (i = 0; i < size; i++)
        {
            if (d[i] != s[i])
            {
                ret = SWC_COMPARE_KEY_FAILED;
                break;
            }
        }
    }

    return ret;
}
FUNC(Std_ReturnType, ASW_DCM_CODE) CompareKey_L1(VAR(uint32,AUTOMATIC) KeyLen_32,P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
{

	Std_ReturnType retValue = RTE_E_OK;

	 unsigned char Deaultvalue[16] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu,0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu};
	  struct AES_ctx ctx;
	  unsigned char mac_key[16]={0,};

      if(Eeprom_PINCODE[23] == CRC8forSAEJ1850(Eeprom_PINCODE, 23))
      {
        for(uint8 i = 0; i < 16; i++)
        {
            Deaultvalue[i] = Eeprom_PINCODE[i];
        }     
      }
	 aes128_init_cmac(&ctx, Deaultvalue);

        aes128_cmac(&ctx, PrimitiveSeed, 16, mac_key);
	if (Bl_MemCmp(Key, mac_key, 16)==RTE_E_OK)
		{
        Ids_SecurityAccLvType data;
        data = 1;

        Ids_SetSecurityEventWithContextData(IDS_SECURITY_ACCESS_VALIDATION_SUCCESS, (uint8_t *)&data, sizeof(Ids_SecurityAccLvType));
		}
		else{
			retValue = SWC_COMPARE_KEY_FAILED;
		 }


	return (retValue);
}



FUNC(Std_ReturnType, ASW_DCM_CODE) CompareKey_OTA(VAR(uint32,AUTOMATIC) KeyLen_32,P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)








{

	Std_ReturnType retValue = RTE_E_OK;

	 unsigned char Deaultvalue[16] = {0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu,0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu};
	  struct AES_ctx ctx;
	  unsigned char mac_key[16]={0,};
      if(Eeprom_PINCODE[23] == CRC8forSAEJ1850(Eeprom_PINCODE, 23))
      {
        for(uint8 i = 0; i < 16; i++)
        {
            Deaultvalue[i] = Eeprom_PINCODE[i];
        }     
      }

	 aes128_init_cmac(&ctx, Deaultvalue);

         aes128_cmac(&ctx, PrimitiveSeed, 16, mac_key);
	if (Bl_MemCmp(Key, mac_key, 16)==RTE_E_OK)
		{
        Ids_SecurityAccLvType data;
        data = 1;

        Ids_SetSecurityEventWithContextData(IDS_SECURITY_ACCESS_VALIDATION_SUCCESS, (uint8_t *)&data, sizeof(Ids_SecurityAccLvType));
		}
		else{
			retValue = SWC_COMPARE_KEY_FAILED;
		 }


	return (retValue);
}


FUNC(Std_ReturnType, ASW_DCM_CODE) GetSeed_L1(VAR(Dcm_SecLevelType,AUTOMATIC) SecLevel_u8,VAR(uint32,AUTOMATIC) Seedlen_u32,VAR(uint32,AUTOMATIC) AccDataRecsize_u32,P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) SecurityAccessDataRecord,P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Seed,VAR(Dcm_OpStatusType,AUTOMATIC) OpStatus,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
		{
	Std_ReturnType retValue = RTE_E_OK;
    unsigned char key1[16] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    unsigned char iv[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    struct AES_ctx ctx;
    uint32 timer_value;
    timer_value = STM0_TIM0.U;
    for(int i=0;i<16;i++)
    {
    	GetSeed[i] = (uint8)(((timer_value >> i) ^ 0x64) & 0xFF);
    }
    
    if(Eeprom_PINCODE[23] == CRC8forSAEJ1850(Eeprom_PINCODE, 23))
    {
        for(uint8 i = 0; i < 16; i++)
        {
            key1[i] = Eeprom_PINCODE[i];
        }     
    }    
    AES_init_ctx_iv(&ctx, key1, iv);
    AES_CBC_encrypt_buffer(&ctx, &GetSeed, 16);
    for(int i=0;i<16;i++)
    {
     Seed[i] = GetSeed[i];
     PrimitiveSeed[i] = Seed[i];
    }
	return (retValue);
	/**Seed = DcmSeed[0];
	*(Seed+1) = DcmSeed[1];
	*(Seed+2) = DcmSeed[2];
	*(Seed+3) = DcmSeed[3];
	return (retValue);*/
}



FUNC(Std_ReturnType, ASW_DCM_CODE) GetSeed_OTA(VAR(Dcm_SecLevelType,AUTOMATIC) SecLevel_u8,VAR(uint32,AUTOMATIC) Seedlen_u32,VAR(uint32,AUTOMATIC) AccDataRecsize_u32,P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) SecurityAccessDataRecord,P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Seed,VAR(Dcm_OpStatusType,AUTOMATIC) OpStatus,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)


		{
	Std_ReturnType retValue = RTE_E_OK;
    unsigned char key1[16] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    unsigned char iv[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    struct AES_ctx ctx;
    uint32 timer_value;
    timer_value = STM0_TIM0.U;
    for(int i=0;i<16;i++)
    {
    	GetSeed[i] = (uint8)(((timer_value >> i) ^ 0x64) & 0xFF);
    }

    if(Eeprom_PINCODE[23] == CRC8forSAEJ1850(Eeprom_PINCODE, 23))
    {
        for(uint8 i = 0; i < 16; i++)
        {
            key1[i] = Eeprom_PINCODE[i];
        }     
    }     
    AES_init_ctx_iv(&ctx, key1, iv);
    AES_CBC_encrypt_buffer(&ctx, &GetSeed, 16);
    for(int i=0;i<16;i++)
    {
     Seed[i] = GetSeed[i];
     PrimitiveSeed[i] = Seed[i];
    }
	return (retValue);
}

#define ASW_DCM_STOP_SEC_CODE
#include "ASW_DCM_MemMap.h"
