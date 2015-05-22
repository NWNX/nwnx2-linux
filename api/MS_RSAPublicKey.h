#ifndef _MS_RSAPUBLICKEY_H_
#define _MS_RSAPUBLICKEY_H_
#include "nwndef.h"

class MS_RSAPublicKey
{
public:
    int encryptDDCipher(unsigned char *, unsigned char const *);
    int encryptHash(unsigned char *, char const *);
    int encrypt(MS_RSAVLong const &);
    int exportPublicKey(unsigned char *);
    int importPublicKey(unsigned char *);

};
#endif
