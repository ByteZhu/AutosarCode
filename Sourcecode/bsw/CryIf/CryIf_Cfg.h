/*
**********************************************************************************************************************
* Component: rba.CUBAS.SecServices.CryIf
* Major Version: 2
* Minor Version: 0
* Patch Version: 0
**********************************************************************************************************************
*/


#ifndef CRYIF_CFG_H
#define CRYIF_CFG_H

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

#define CRYIF_CFG_CHANNEL_COUNT                  (4U)
#define CRYIF_CFG_KEY_COUNT                      (3U)
#define CRYIF_CFG_KEY_ELEMENT_COPY_MAX_SIZE      (16U)

#define CRYIF_CFG_CRYPTO_MODULEINDEX    (0U)

//Defines of AUTOSAR Symbolic Name values
//TRACE[SWS_BSW_00200][TPS_ECUC_02108]
#define CryIfConf_CryIfChannel_CryIfChannel_GEN   (0U)
#define CryIfConf_CryIfChannel_CryIfChannel_VER   (1U)
#define CryIfConf_CryIfChannel_CryIfChannel_AEAD_ENC   (2U)
#define CryIfConf_CryIfChannel_CryIfChannel_AEAD_DEC   (3U)
#define CryIfConf_CryIfKey_CryIfKey_DevKey   (0U)
#define CryIfConf_CryIfKey_CryIfKey_SecOC_CMAC_Ele   (1U)
#define CryIfConf_CryIfKey_CryIfKey_SecOC_CMAC_Ele1   (2U)

#endif /* CRYIF_CFG_H */


