#ifndef _CBWCMD5_H_
#define _CBWCMD5_H_
#include "nwndef.h"

class CBWCMD5
{
public:
	int Decrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &);
	int Decrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &);
	int EncryptBlock(unsigned long const *);
	int EncryptFinalBlock(unsigned long const *, unsigned long);
	int Encrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &);
	int Encrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &);
	int F(unsigned long, unsigned long, unsigned long);
	int G(unsigned long, unsigned long, unsigned long);
	int GetDecryptedSize(unsigned long, unsigned long &);
	int GetEncryptedSize(unsigned long, unsigned long &);
	int GetStateSize(unsigned long &);
	int GetState(void *);
	int H(unsigned long, unsigned long, unsigned long);
	int I(unsigned long, unsigned long, unsigned long);
	int Reset();
	int SetKey(unsigned char *, unsigned long, unsigned char &);
	int SetState(void *, unsigned long);
	~CBWCMD5();
	CBWCMD5();

};
#endif
