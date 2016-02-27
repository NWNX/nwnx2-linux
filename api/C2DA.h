#ifndef _C2DA_H_
#define _C2DA_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CResRef.h"
#include "nwnstructs.h"

class C2DA : CResHelper<CRes2DA>
{
public:
    int GetCExoStringEntry(CExoString const &, CExoString const &, CExoString *);
    int GetCExoStringEntry(CExoString const &, int, CExoString *);
    int GetCExoStringEntry(int, CExoString const &, CExoString *);
    int GetCExoStringEntry(int, int, CExoString *);
    int GetColumnIndex(CExoString const &);
    int GetFLOATEntry(CExoString const &, CExoString const &, float *);
    int GetFLOATEntry(CExoString const &, int, float *);
    int GetFLOATEntry(int, CExoString const &, float *);
    int GetFLOATEntry(int, int, float *);
    int GetINTEntry(CExoString const &, CExoString const &, int *);
    int GetINTEntry(CExoString const &, int, int *);
    int GetINTEntry(int, CExoString const &, int *);
    int GetINTEntry(int, int, int *);
    int GetNextLineLength(char *, unsigned long);
    int GetNextToken(char **, unsigned long *, char *, unsigned long *);
    int GetNumColumns();
    int GetNumRows();
    int GetRowIndex(CExoString const &);
    int Load2DArray();
    int SetBlankEntry(CExoString, CExoString);
    int SetBlankEntry(CExoString, int);
    int SetBlankEntry(int, CExoString);
    int SetBlankEntry(int, int);
    int SetCExoStringEntry(CExoString, CExoString, CExoString);
    int SetCExoStringEntry(CExoString, int, CExoString);
    int SetCExoStringEntry(int, CExoString, CExoString);
    int SetCExoStringEntry(int, int, CExoString);
    int SetFLOATEntry(CExoString, CExoString, float);
    int SetFLOATEntry(CExoString, int, float);
    int SetFLOATEntry(int, CExoString, float);
    int SetFLOATEntry(int, int, float);
    int SetINTEntry(CExoString, CExoString, int);
    int SetINTEntry(CExoString, int, int);
    int SetINTEntry(int, CExoString, int);
    int SetINTEntry(int, int, int);
    int SkipNewLines(char **, unsigned long *);
    void Unload2DArray();
    ~C2DA();
    C2DA();
    C2DA(CResRef, int);

    /* 0x1C/28 */ CExoString m_sDefaultValue;
    /* 0x24/36 */ CExoString *m_pRowLabel;
    /* 0x28/40 */ CExoString *m_pColumnLabel;
    /* 0x2C/44 */ CExoString **m_pArrayData;
    /* 0x30/48 */ unsigned long m_nNumRows;
    /* 0x34/52 */ unsigned long m_nNumColumns;
    /* 0x38/56 */ unsigned long m_bLoaded;
};
#endif
