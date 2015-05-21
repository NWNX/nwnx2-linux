#ifndef _CERFSTRING_H_
#define _CERFSTRING_H_
#include "nwndef.h"
#include "CExoString.h"

class CERFString
{
public:
    CExoString GetText();
    int Read();
    int Reset();
    void SetText(CExoString &);
    int Write(CExoFile &);
    ~CERFString();
    CERFString();

};
#endif
