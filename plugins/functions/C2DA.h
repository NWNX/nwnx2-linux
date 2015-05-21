#include "typedefs.h"
#include "NWNStructures.h"

#ifndef C2DA_H_
#define C2DA_H_


/*
00000000 C2DAClass struc ; (sizeof=0x3C)
00000000 field_0 dd ?
00000004 CRes2DA dd ?                            ; offset
00000008 Name db 16 dup(?)                       ; string(C)
00000018 C2DA dd ?                               ; offset
0000001C field_1C dd ?
00000020 field_20 dd ?
00000024 IDList dd ?                             ; offset
00000028 CoulmnNames dd ?                        ; offset
0000002C Rows dd ?                               ; offset
00000030 RowCount dd ?
00000034 ColumnCount dd ?
00000038 field_38 dd ?
0000003C C2DAClass ends
*/

class C2DA
{
public:
    dword field_0;
    void *CRes2DA;
    char Name[16];
    void *C2DAClass;
    dword field_1C;
    dword field_20;
    CExoString *IDList;
    CExoString *ColumnNames;
    CExoString **Rows;
    dword RowCount;
    dword ColumnCount;
    dword field_38;

    int GetColumnID(char *sColumn);
    int GetRowID(unsigned int nRow);
};

#endif
