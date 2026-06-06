//
// Created by dawad on 2023-03-25.
//
// Version: 1.1
// Author: dawad

#ifndef CRYPTO_SIMPLE_CMAC_CRYPTO_H
#define CRYPTO_SIMPLE_CMAC_CRYPTO_H
#include"aes_crypto.h"
#include"sha.h"
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct{
		uint32_t eK[44], dK[44];    // encKey, decKey
		int Nr; // 10 rounds
	}AesKey;
	void printHex(uint8_t *ptr, int len, char *tag);
#define BLOCKSIZE 16  //AES-128分组长度为16字节

	// uint8_t y[4] -> uint32_t x
#define LOAD32H(x, y) \
do {                                                                                  \
	(x) = ((uint32_t)((y)[0] & 0xff) << 24) | ((uint32_t)((y)[1] & 0xff) << 16) |     \
	((uint32_t)((y)[2] & 0xff) << 8) | ((uint32_t)((y)[3] & 0xff));                   \
	} while (0)

	// uint32_t x -> uint8_t y[4]
#define STORE32H(x, y) \
	do {                                                                              \
	(y)[0] = (uint8_t)(((x) >> 24) & 0xff); (y)[1] = (uint8_t)(((x) >> 16) & 0xff);   \
	(y)[2] = (uint8_t)(((x) >> 8) & 0xff); (y)[3] = (uint8_t)((x)& 0xff);             \
	} while (0)

	// 从uint32_t x中提取从低位开始的第n个字节
#define BYTE(x, n) (((x) >> (8 * (n))) & 0xff)

	/* used for keyExpansion */
	// 字节替换然后循环左移1位
#define MIX(x) (((S[BYTE(x, 2)] << 24) & 0xff000000) ^ ((S[BYTE(x, 1)] << 16) & 0xff0000) ^ \
	((S[BYTE(x, 0)] << 8) & 0xff00) ^ (S[BYTE(x, 3)] & 0xff))

	// uint32_t x循环左移n位
#define ROF32(x, n)  (((x) << (n)) | ((x) >> (32-(n))))
	// uint32_t x循环右移n位
#define ROR32(x, n)  (((x) >> (n)) | ((x) << (32-(n))))
   
/*
* @abstract This function mac data with cbc mode
*
* @param key     [IN]  the AES key
* @param input   [IN]  the buffer holding the input data.
* @param length  [IN]  the input data len
* @param mac     [OUT] the buffer holding the output data.
*
* @return 0 on success
*/
	extern void AES_CMAC(unsigned char *key, unsigned char *input, int length, unsigned char *mac);

#ifdef __cplusplus
}
#endif
#endif
