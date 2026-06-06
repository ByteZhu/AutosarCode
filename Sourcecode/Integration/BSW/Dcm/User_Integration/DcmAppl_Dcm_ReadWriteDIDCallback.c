#include "Dcm_Cfg_Prot.h"
#include "Dcm.h"
#include "CDD_FVM.h"
#include "Crypto.h"

#include "NvM.h"
#include "ASW_NVM.h"
#include "NVM_types.h"
#include "GlobalVar.h"
#include "MemIf_Types.h"
#include "Fls.h"

// extern volatile sint32 Fv_MotorCurrent_Qact;
// extern const sint32 fsMotorMaxFocCurrentQ;
// extern volatile Int16 Fv_HighFailFlag;
// #if 0
// extern volatile HOLD Fv_WhichMode;
// extern volatile ANGLE_STS Fv_AngleMidValidFlag;
// #endif
// extern volatile sint16 Fv_TempSysCel;
// extern volatile sint16 Fv_StrAng;
// extern volatile sint16 Fv_StrAngOffset;
// extern volatile uint16 Fv_FaultClass_Torque;
// extern volatile uint16 Fv_VehSpdNew;
// extern volatile sint16 Fv_SysPower;
// extern volatile sint16 Fv_StrTrq0;
// extern volatile Int16 Fv_FriCompAdptiveTorque;
// extern volatile UInt8 Fv_PowerMode;
// extern volatile UInt8 Fv_EXT_UsageModeReq;
// extern volatile UInt8 Fv_APA_ControlSts;
// #include "IdsM.h"
// #define GEELY_PART_NUMBER_SIZE                      (8)
// #define GEELY_SBL_VERSION_SIZE                      (7)
// #define GEELY_VOLVO_PART_NUMBER_SIZE                (7)
// #define GEELY_PN_TOTAL_LENGTH                       (GEELY_PART_NUMBER_SIZE + GEELY_VOLVO_PART_NUMBER_SIZE)
// #define GEELY_SSI_NUMBER_SIZE                       (6)

// #pragma section farrom "pn_ecu_ca"
// const uint8 g_GeelyECUCorePartNumber[GEELY_PN_TOTAL_LENGTH] =
// {
//     /*660833212020/B--F1AA*/
//     0x66, 0x08, 0x35, 0x33, 0x21, 0x20, 0x20, 'B', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };
// //MOD to 2020B by liuyang at 241121
// #pragma section farrom "pn_ecu_da"
// const uint8 g_GeelyECUDeliveryPartNumber[GEELY_PN_TOTAL_LENGTH]  =
// {
//     /*6608233503/A---F1AB*/
//     0x66,0x08, 0x23, 0x35, 0x03, 0x20, 0x20, 'A', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };

// #pragma section farrom "pn_pbl_sw"
// const uint8 g_GeelyPBLPartNumber[25] =
// {
//     /*6608310204/D---F1AE*/
// 	0x03,0x66,0x08,0x35,0x33,0x22,0x20,0x20,'B',0x66,0x08,0x31,0x01,0x98,0x20,0x20,'A',0x66,0x08,0x31,0x01,0x97,0x20,0x20,'A'
// }; // MOD by liuyang  to 'B' at 241115

// #pragma section farrom "pn_pbl_dd"
// const uint8 g_GeelyPBLDiagPartNumber[GEELY_PN_TOTAL_LENGTH] =
// {
//     /*6608310203/A---0xF1A1u*/
//       0x66, 0x08, 0x31, 0x02, 0x03, 0x20, 0x20, 'A', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };
// #pragma section farrom "pn_ecu_ssi"
// const uint8 g_GeelyPBLSystemSupplierId[GEELY_SSI_NUMBER_SIZE] =
// {
//     'X', 'B', 'D', 'Z'
// };

// #pragma section farrom "pn_SXDI_SWLM"
// const uint8 g_GeelyAPPSXDI_SWLM[GEELY_PN_TOTAL_LENGTH] =
// {
// 	/*6608310199/A---0xF1A0u*/
// 	  0x66, 0x08, 0x31, 0x01, 0x99, 0x20, 0x20, 'A', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };

// #pragma section farrom "pn_ecu_APPDD"
// const uint8 g_GeelyAPPDiagDatabasePN[GEELY_PN_TOTAL_LENGTH] =
// {
// 	/*6608310199/A---0xF120u*/
// 	  0x66, 0x08, 0x31, 0x01, 0x99, 0x20, 'A', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };

// #pragma section farrom "pn_ecu_core"
// const uint8 g_Geelyecu_corePN[GEELY_PN_TOTAL_LENGTH] =
// {
// 	/*6608310199/A---0xF12Au*/
// 	  0x66, 0x08, 0x31, 0x01, 0x99, 0x20, 'A', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };

// #pragma section farrom "pn_ecu_Delivery_Assembly"
// const uint8 g_Geelyecu_Delivery_Assembly_PN[GEELY_PN_TOTAL_LENGTH] =
// {
// 	/*6608310199/A---0xF12Bu*/
// 	  0x66, 0x08, 0x31, 0x01, 0x99, 0x20, 'A', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };

// #pragma section farrom "pn_ecu_Software_PartNumbers"
// const uint8 g_Geelyecu_Software_PartNumbers[22] =
// {
// 	/*6608310199/A---0xF12Eu*/
// 		0x03,0x66,0x08,0x35,0x33,0x22,0x20,'A',0x66,0x08,0x31,0x01,0x98,0x20,'A',0x66,0x08,0x31,0x01,0x97,0x20,'A'
// };

// #pragma section farrom "pn_ecu_F1A5"
// const uint8 g_GeelyECU_F1A5[GEELY_PN_TOTAL_LENGTH]  =
// {
//     /*6608310204/B---F1A5*/
//     0x66,0x08, 0x35, 0x33, 0x24, 0x20, 0x20, 'B', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"

/***Extern declarations for XXX_ReadData of type USE_DATA_SYNCH_FNC ***/
Std_ReturnType DID_2145_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_2146_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_2147_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_217D_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_217E_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_21AB_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_21AC_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_21AD_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_2221_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_3012_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_3017_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_302C_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_330C_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D005_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D01C_ReadFnc (Dcm_OpStatusType OpStatus, uint8 * Data)
{
    /*  add your handler function*/
    const uint32 KEYADDRESS = 0xAF008000 + 4;
    const uint32 KEYSIZE = 292;

    Rte_memcpy(Data, (uint8*)KEYADDRESS, KEYSIZE);
    
    return RTE_E_OK;
}
Std_ReturnType DID_D01C_WriteFnc (const uint8 * Data,Dcm_OpStatusType OpStatus,Dcm_NegativeResponseCodeType * ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;
    MemIf_JobResultType memJobResult;
    const uint32 KEYMAGIC = 0x5A5A5A5A;
    const uint32 KEYADDRESS = 0xAF008000;
    const uint32 KEYOFFSET = KEYADDRESS - 0xAF000000;
    const uint32 KEYSIZE = 292;
    uint8 storeBuffer[296] = {0};

    Rte_memcpy(&storeBuffer[0], (uint8*)&KEYMAGIC, 4);
    Rte_memcpy(&storeBuffer[4], Data, KEYSIZE);

    /*  add your handler function*/
    // if (DCM_INITIAL == OpStatus)
    // {
    //     if ((*((uint32*)KEYADDRESS)) == KEYMAGIC)
    //     {
    //         *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    //         ret = RTE_E_INVALID;
    //     }
    //     else
    //     {
    //         *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    //         ret = RTE_E_INVALID;
    //     }
    // }
    // else
    {
        Fls_Erase(KEYOFFSET, 1);
        while(Fls_GetJobResult() == MEMIF_JOB_PENDING)
        {
            Fls_MainFunction();
            memJobResult = Fls_GetJobResult();
        }

        ret = (memJobResult == MEMIF_JOB_OK) ? RTE_E_OK : RTE_E_INVALID;
        
        if (E_OK == ret)
        {
            Fls_Write(KEYOFFSET, storeBuffer, sizeof(storeBuffer));
            while(Fls_GetJobResult() == MEMIF_JOB_PENDING)
            {
                Fls_MainFunction();
                memJobResult = Fls_GetJobResult();
            }

            ret = (memJobResult == MEMIF_JOB_OK) ? RTE_E_OK : RTE_E_INVALID;
        }

        if (ret != RTE_E_OK)
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
        else
        {
            *ErrorCode = DCM_E_OK;
        }
    }

    return ret;
}
Std_ReturnType DID_D0B5_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D118_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D11C_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D134_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D900_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D901_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D902_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D904_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D905_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D906_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D908_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D909_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_D90A_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_DD00_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_DD01_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_DD02_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_DD06_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_DD07_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_DD0A_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_DD0C_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_E103_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F120_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F121_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F125_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F126_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F12A_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F12B_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F12E_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F186_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F18A_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F18C_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F1A0_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F1A1_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F1A5_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F1AA_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F1AB_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F1AE_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}
Std_ReturnType DID_F1D0_ReadFnc (uint8 * Data)
{
    /*  add your handler function*/

    return RTE_E_OK;
}


#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_MemMap.h"
