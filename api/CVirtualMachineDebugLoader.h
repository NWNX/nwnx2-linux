#ifndef _CVIRTUALMACHINEDEBUGLOADER_H_
#define _CVIRTUALMACHINEDEBUGLOADER_H_
#include "nwndef.h"

class CVirtualMachineDebugLoader
{
public:
    int DemandDebugInfo(CExoString *);
    int GetDataPtr();
    int GetSize();
    int ReleaseDebugInfo();
    ~CVirtualMachineDebugLoader();

};
#endif
