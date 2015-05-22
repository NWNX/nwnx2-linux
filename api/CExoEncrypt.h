#ifndef _CEXOENCRYPT_H_
#define _CEXOENCRYPT_H_
#include "nwndef.h"
#include "CExoString.h"

class CExoEncrypt
{
public:
    CExoString EncryptString(CExoString const &);
    CExoString GenerateChallenge(unsigned short);

};
#endif
