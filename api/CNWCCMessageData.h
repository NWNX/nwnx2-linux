#ifndef _CNWCCMESSAGEDATA_H_
#define _CNWCCMESSAGEDATA_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CExoArrayList.h"

class CNWCCMessageData
{
public:
    int ClearData();
    void CopyTo(CNWCCMessageData *);
    int GetFloat(int);
    int GetInteger(int);
    unsigned long GetObjectID(int);
    CExoString GetString(int);
    int LoadData(CResGFF *, CResStruct *);
    int SaveData(CResGFF *, CResStruct *);
    int SetFloat(int, float);
    void SetInteger(int, int);
    void SetObjectID(int, unsigned long);
    void SetString(int, CExoString);
    ~CNWCCMessageData();
    CNWCCMessageData();

    /* 0x0/0 */ void *field_0;
    /* (mtype:CExoArrayList<int>) */
    /* 0x4/4 */ CExoArrayList<int> IntList;
    /* (mtype:CExoArrayList<float>) */
    /* 0x10/16 */ CExoArrayList<float> FloatList;
    /* (mtype:CExoArrayList<CExoString>) */
    /* 0x1C/28 */ CExoArrayList<CExoString> StringList;
    /* (mtype:CExoArrayList<unsigned long>) */
    /* 0x28/40 */ CExoArrayList<unsigned long> ObjectIDList;
};
#endif
