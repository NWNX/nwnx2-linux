#ifndef _CDUTIL_H_
#define _CDUTIL_H_
#include "nwndef.h"

class CDUtil
{
public:
    int CalculateCRC(char *, int, char *, int, char *&, int);
    int CreateChallengeString(unsigned long);
    int DecodeBase(char *, int);
    int EncodeBase(unsigned long long, char *, int);
    int GenerateResponse(CExoString const &, CExoString const &, CExoString &, CExoString &);
    void InitializeBaseConvert();
    void InitializeCrc();
    void Initialize();
    int ScrambleKey(char *, char const *, char const *, char const *, int);
    void UnScrambleKey(char const *, char *, char *, char *);
    int ValidateKey(char *);

};
#endif
