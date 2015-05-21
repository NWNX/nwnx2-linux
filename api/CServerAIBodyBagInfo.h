#ifndef _CSERVERAIBODYBAGINFO_H_
#define _CSERVERAIBODYBAGINFO_H_
#include "nwndef.h"

class CServerAIBodyBagInfo
{
public:
    int LoadBodyBag(CResGFF *, CResStruct *);
    int SaveBodyBag(CResGFF *, CResStruct *);

};
#endif
