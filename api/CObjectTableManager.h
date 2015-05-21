#ifndef _COBJECTTABLEMANAGER_H_
#define _COBJECTTABLEMANAGER_H_
#include "nwndef.h"

class CObjectTableManager
{
public:
    int AddID(unsigned long, unsigned long *, unsigned long);
    void ClearAll();
    int CreateNewPlayer(unsigned long);
    int GetIDFromIndex(unsigned long, unsigned long);
    int GetIndexFromID(unsigned long, unsigned long);
    int RemovePlayer(unsigned long);
    int Touch(unsigned long, unsigned long);
    ~CObjectTableManager();
    CObjectTableManager();

};
#endif
