#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H

#include "Std_Types.h"
#include "Crypto_GeneralTypes.h"

#define CRYPTO_OBJ_NUM        4
#define CRYPTO_PRIMITIVE_NUM  4

#define CRYPTO_KEY_NUM        3
#define CRYPTO_KEYELEMENT_NUM 3

typedef enum
{
	ENUM_KEYTYPE_NONE,
	ENUM_KEYTYPE_DEV,
	ENUM_KEYTYPE_SECOC,
}tp_Enum_KeyType;

typedef struct
{
	uint32 KeyElementId;
	boolean   KeyEleValid;
	boolean   NvmEleKeyValid;
	uint16 ElementSize;
	uint8 *Element_Pt;
	uint8 *ValidCheck_pt;
	boolean ReadAuth;
	boolean WriteAuth;
	uint32 NvmOffset;
}KeyElement_Struct;

typedef struct
{
	uint32             KeyId;
	tp_Enum_KeyType    KeyType;
	KeyElement_Struct  KeyElements[CRYPTO_KEYELEMENT_NUM];
}Key_Struct;


typedef struct
{
	const Crypto_ServiceInfoType service;
	Crypto_AlgorithmFamilyType family;            /* The family of the algorithm */
    Crypto_AlgorithmFamilyType secondaryFamily;   /* The secondary family of the algorithm */
    Crypto_AlgorithmModeType mode;                /* The operation mode to be used with that algorithm */
}Crypto_PrimitiveRef_Struct; 



typedef struct
{
	uint32 CryptoDriverObjectId; 
	uint16 CryptoQueueSize;
	Crypto_PrimitiveRef_Struct *Crypto_PrimitiveRef;	
}Crypto_Object_Struct;




extern Crypto_Object_Struct Crypto_Objects[CRYPTO_OBJ_NUM];
extern Crypto_PrimitiveRef_Struct Crypto_Primitives[CRYPTO_PRIMITIVE_NUM];
extern Key_Struct CryptoKeys[CRYPTO_KEY_NUM];

#endif
