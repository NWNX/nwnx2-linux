#ifndef _CTLKFILE_H_
#define _CTLKFILE_H_
#include "nwndef.h"
#include "CExoString.h"

class CTlkFile
{
public:
    int ReadHeader();
    CTlkFile(CExoString);

};
#endif
