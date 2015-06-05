#ifndef _CGAMEOBJECTARRAY_H_
#define _CGAMEOBJECTARRAY_H_
#include "nwndef.h"

class CGameObjectArray
{
public:
    int AddCharacterObjectAtPos(unsigned long, CGameObject *);
    int AddExternalObject(unsigned long &, CGameObject *, int);
    unsigned char AddInternalObject(unsigned long &, CGameObject *, int);
    unsigned char AddObjectAtPos(unsigned long, CGameObject *);
    int Clean(unsigned short);
    unsigned char Delete(unsigned long);
    int Delete(unsigned long, CGameObject **);
    int GetGameObject(unsigned long, CGameObject **);
    ~CGameObjectArray();
    CGameObjectArray(int);

    /* 0x0/0 */ CGameObjectArrayElement **Objects;
    /* 0x4/4 */ unsigned long ObjectPointer;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long PlayerPointer;
    /* 0x10/16 */ unsigned long ExternalPointer;
    /* 0x14/20 */ unsigned long field_14;
};
#endif
