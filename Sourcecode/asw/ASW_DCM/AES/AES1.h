#ifndef _AES1_H_
#define _AES1_H_
#include <stdint.h>
#include <stddef.h>
#define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only
#define AES_KEYLEN 16 // Key length in bytes
#define AES_keyExpSize 176
struct AES_ctx
{
	unsigned char RoundKey[AES_keyExpSize];
	unsigned char Iv[AES_BLOCKLEN];
};
void AES_init_ctx_iv(struct AES_ctx* ctx, const unsigned char* key, const unsigned char* iv);
void AES_CBC_encrypt_buffer(struct AES_ctx* ctx, unsigned char* buf, size_t length);
void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, unsigned char* buf, size_t length);
#endif // _AES_H_
