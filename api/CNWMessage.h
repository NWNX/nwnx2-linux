#ifndef _CNWMESSAGE_H_
#define _CNWMESSAGE_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CResRef.h"

class CNWMessage
{
public:
    void ClearReadMessage();
    void CreateWriteMessage(unsigned long, unsigned long, int);
    void ExtendWriteBuffer(unsigned long);
    void ExtendWriteFragmentsBuffer(unsigned long);
    int GetObjectLookupTable();
    int GetWriteMessage(unsigned char **, unsigned long *);
    int MessageMoreDataToRead();
    int MessageReadOverflow(int);
    int MessageReadUnderflow(int);
    unsigned long PeekAtWriteMessageSize();
    int ReadBOOL();
    unsigned char ReadBYTE(int);
    int ReadBit(unsigned char);
    __int64 ReadBits(int);
    CExoString ReadCExoString(int);
    char ReadCHAR(int);
    CResRef ReadCResRef(int);
    int ReadDOUBLE(double, double, int);
    int ReadDOUBLE(double, int);
    int ReadDWORD64(int);
    unsigned long ReadDWORD(int);
    int ReadFLOAT(float, float, int);
    float ReadFLOAT(float, int);
    int ReadINT64(int);
    int ReadINT(int);
    int ReadSHORT(int);
    int ReadSigned(int);
    unsigned __int64 ReadUnsigned(int);
    void * ReadVOIDPtr(int);
    unsigned short ReadWORD(int);
    void SetReadMessage(unsigned char *, unsigned long, unsigned long, int);
    void WriteBOOL(int);
    void WriteBYTE(unsigned char, int);
    void WriteBit(unsigned char);
    int WriteBits(unsigned long long, int);
    void WriteCExoString(CExoString, int);
    void WriteCHAR(char, int);
    void WriteCResRef(CResRef, int);
    int WriteDOUBLE(double, double, double, int);
    int WriteDOUBLE(double, double, int);
    int WriteDWORD64(unsigned long long, int);
    void WriteDWORD(unsigned long, int);
    void WriteFLOAT(float, float, float, int);
    void WriteFLOAT(float, float, int);
    int WriteINT64(long long, int);
    void WriteINT(int, int);
    void WriteSHORT(short, int);
    int WriteSigned(long long, int);
    int WriteUnsigned(unsigned long long, int);
    void WriteVOIDPtr(void *, int);
    void WriteWORD(unsigned short, int);
    ~CNWMessage();
    CNWMessage();

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long field_4;
    /* 0x8/8 */ unsigned long field_8;
    /* 0xC/12 */ unsigned long field_C;
    /* 0x10/16 */ unsigned long field_10;
    /* 0x14/20 */ unsigned long field_14;
    /* 0x18/24 */ unsigned long field_18;
    /* 0x1C/28 */ unsigned long field_1C;
    /* 0x20/32 */ unsigned long field_20;
    /* 0x24/36 */ unsigned long field_24;
    /* 0x28/40 */ unsigned long field_28;
    /* 0x2C/44 */ unsigned long field_2C;
    /* 0x30/48 */ unsigned long field_30;
    /* 0x34/52 */ unsigned long field_34;
    /* 0x38/56 */ unsigned long field_38;
    /* 0x3C/60 */ unsigned long field_3C;
    /* 0x40/64 */ unsigned long field_40;
    /* 0x44/68 */ unsigned long field_44;
    /* 0x48/72 */ unsigned long field_48;
    /* 0x4C/76 */ unsigned long field_4C;
};
#endif
