#ifndef _CBWCBLOWFISH_H_
#define _CBWCBLOWFISH_H_
#include "nwndef.h"

class CBWCBlowFish
{
public:
	int BlockToBytes(CBWCBlowFishBlock const &, unsigned char *);
	int BytesToBlock(unsigned char const *, CBWCBlowFishBlock &);
	int DecryptBlock(CBWCBlowFishBlock &);
	int Decrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &);
	int Decrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &);
	int EncryptBlock(CBWCBlowFishBlock &);
	int Encrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &);
	int Encrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &);
	int F(unsigned long);
	int GetDecryptedSize(unsigned long, unsigned long &);
	int GetEncryptedSize(unsigned long, unsigned long &);
	int GetLowOrderByte(unsigned long);
	int GetStateSize(unsigned long &);
	int GetState(void *);
	int ResetChain();
	int ResetKey();
	int SetKey(unsigned char *, unsigned long, unsigned char &);
	int SetState(void *, unsigned long);
	~CBWCBlowFish();
	CBWCBlowFish();
	CBWCBlowFish(CBWCBlowFish const &);

};
#endif
