
#if !defined(CGameObjectArray_h_)
#define CGameObjectArray_h_

/*
00000000 CGameObjectArrayElement struc ; (sizeof=0xC)
00000000 OID dd ?
00000004 GameObject dd ?
00000008 field_8 dd ?
0000000C CGameObjectArrayElement ends
*/

struct CGameObjectArrayElement {
    dword ObjectID;
    char *Object;
    dword field_8;
};

/*
00000000 CGameObjectArray struc ; (sizeof=0x18)
00000000 Objects dd ?                            ; offset
00000004 ObjectPointer dd ?
00000008 field_8 dd ?
0000000C PlayerPointer dd ?
00000010 field_10 dd ?
00000014 field_14 dd ?
00000018 CGameObjectArray ends
*/

struct CGameObjectArray {
    CGameObjectArrayElement **Objects;
    dword ObjectPointer;
    dword field_8;
    dword PlayerPointer;
    dword field_10;
    dword field_14;
};


#endif

