#ifndef _CVIRTUALMACHINEFILE_H_
#define _CVIRTUALMACHINEFILE_H_
#include "nwndef.h"
#include "CResRef.h"

class CVirtualMachineFile
{
public:
    int GetData(char **, unsigned long &);
    int LoadFile(CExoString const &);
    int UnloadFile();
    ~CVirtualMachineFile();
    CVirtualMachineFile();

    /* 0x0/0 */ unsigned long m_bAutoRequest;
    /* 0x4/4 */ CResNCS *m_pRes;
    /* 0x8/8 */ CResRef m_cResRef;
    /* 0x18/24 */ void *vtable;
};
#endif
