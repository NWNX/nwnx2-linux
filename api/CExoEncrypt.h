#ifndef _CEXOENCRYPT_H_
#define _CEXOENCRYPT_H_
#include "nwndef.h"

class CExoEncrypt
{
public:
	int EncryptString(CExoString const &);
	int GenerateChallenge(unsigned short);

};
#endif
