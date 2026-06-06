#include "CryIf_Crypto_Wrapper.h"
#include "Crypto_Cfg.h"


uint8 CryptoKeyElement_GCM_DEV_Valid_KeyCheck[4] = {0x00, 0x00, 0x00, 0x00};
uint8 CryptoKeyElement_GCM_DEV_KEY_Ele[16] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8 CryptoKeyElement_GCM_DEV_IV_Ele[12] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

uint8 CryptoKeyElement_SecOC_Valid_KeyCheck[4] = {0x00, 0x00, 0x00, 0x00};
uint8 CryptoKeyElement_SecOC_KEY_Ele[16] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

uint8 CryptoKeyElement_SecOC_1_Valid_KeyCheck[4] = {0x00, 0x00, 0x00, 0x00};
uint8 CryptoKeyElement_SecOC_1_KEY_Ele[16] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};



Key_Struct CryptoKeys[CRYPTO_KEY_NUM] = 
{
	{
		0, ENUM_KEYTYPE_DEV,
		{
			{1, TRUE, FALSE, 16, CryptoKeyElement_GCM_DEV_KEY_Ele, CryptoKeyElement_GCM_DEV_Valid_KeyCheck, TRUE, TRUE, 0},
			{5, TRUE, FALSE, 12, CryptoKeyElement_GCM_DEV_IV_Ele, NULL_PTR, TRUE, TRUE, 0}
		}
	},
	{ 
		1, ENUM_KEYTYPE_SECOC,
		{
			{1, TRUE, FALSE, 16, CryptoKeyElement_SecOC_KEY_Ele, CryptoKeyElement_SecOC_Valid_KeyCheck, TRUE, TRUE, 20},
		}
	},
	{ 
		2, ENUM_KEYTYPE_NONE,
		{
			{1, TRUE, FALSE, 16, CryptoKeyElement_SecOC_1_KEY_Ele, CryptoKeyElement_SecOC_1_Valid_KeyCheck, TRUE, TRUE, 40},
		}
	},

};	

Crypto_PrimitiveRef_Struct Crypto_Primitives[CRYPTO_PRIMITIVE_NUM] = 
{
	{CRYPTO_MACGENERATE, CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_CMAC},
	{CRYPTO_MACVERIFY, CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_CMAC},
	{CRYPTO_AEADENCRYPT, CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_GCM},
	{CRYPTO_AEADDECRYPT, CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, CRYPTO_ALGOMODE_GCM}
};


Crypto_Object_Struct Crypto_Objects[CRYPTO_OBJ_NUM] = 
{
	{0, 0, Crypto_Primitives},
	{1, 0, Crypto_Primitives + 1},
	{2, 0, Crypto_Primitives + 2},
	{3, 0, Crypto_Primitives + 3},
};






























