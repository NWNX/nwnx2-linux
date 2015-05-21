#ifndef _MS_RSAPRIVATEKEY_H_
#define _MS_RSAPRIVATEKEY_H_
#include "nwndef.h"
#include "MS_RSAVLong.h"

class MS_RSAPrivateKey
{
public:
    MS_RSAPrivateKey();
    int create(MS_RSAVLong const &, MS_RSAVLong const &);
    void decryptDDCipher(unsigned char *, unsigned char const *);
    int decryptHash(char *, unsigned char const *);
    MS_RSAVLong decrypt(MS_RSAVLong const &);

};
#endif
