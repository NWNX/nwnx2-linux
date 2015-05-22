#ifndef _CBWCMD5_H_
#define _CBWCMD5_H_
#include "nwndef.h"

class CBWCMD5
{
public:
    int Decrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &);
    int Decrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &);
    void EncryptBlock(unsigned long const *);
    void EncryptFinalBlock(unsigned long const *, unsigned long);
    int Encrypt(unsigned char *, unsigned long, unsigned long &, unsigned char &);
    int Encrypt(unsigned char *, unsigned long, unsigned char *, unsigned long &, unsigned char &);
    static unsigned long F(unsigned long, unsigned long, unsigned long);
    static unsigned long G(unsigned long, unsigned long, unsigned long);
    int GetDecryptedSize(unsigned long, unsigned long &);
    int GetEncryptedSize(unsigned long, unsigned long &);
    int GetStateSize(unsigned long &);
    int GetState(void *);
    static unsigned long H(unsigned long, unsigned long, unsigned long);
    static unsigned long I(unsigned long, unsigned long, unsigned long);
    void Reset();
    int SetKey(unsigned char *, unsigned long, unsigned char &);
    int SetState(void *, unsigned long);
    ~CBWCMD5();
    CBWCMD5();

};
#endif
