#ifndef _CNWMESSAGE_H_
#define _CNWMESSAGE_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CResRef.h"

class CNWMessage
{
public:
	int ClearReadMessage();
	int CreateWriteMessage(unsigned long, unsigned long, int);
	int ExtendWriteBuffer(unsigned long);
	int ExtendWriteFragmentsBuffer(unsigned long);
	int GetObjectLookupTable();
	int GetWriteMessage(unsigned char **, unsigned long *);
	int MessageMoreDataToRead();
	int MessageReadOverflow(int);
	int MessageReadUnderflow(int);
	int PeekAtWriteMessageSize();
	int ReadBOOL();
	int ReadBYTE(int);
	int ReadBit(unsigned char);
	int ReadBits(int);
	int ReadCExoString(int);
	int ReadCHAR(int);
	int ReadCResRef(int);
	int ReadDOUBLE(double, double, int);
	int ReadDOUBLE(double, int);
	int ReadDWORD64(int);
	int ReadDWORD(int);
	int ReadFLOAT(float, float, int);
	int ReadFLOAT(float, int);
	int ReadINT64(int);
	int ReadINT(int);
	int ReadSHORT(int);
	int ReadSigned(int);
	int ReadUnsigned(int);
	int ReadVOIDPtr(int);
	int ReadWORD(int);
	int SetReadMessage(unsigned char *, unsigned long, unsigned long, int);
	int WriteBOOL(int);
	int WriteBYTE(unsigned char, int);
	int WriteBit(unsigned char);
	int WriteBits(unsigned long long, int);
	int WriteCExoString(CExoString, int);
	int WriteCHAR(char, int);
	int WriteCResRef(CResRef, int);
	int WriteDOUBLE(double, double, double, int);
	int WriteDOUBLE(double, double, int);
	int WriteDWORD64(unsigned long long, int);
	int WriteDWORD(unsigned long, int);
	int WriteFLOAT(float, float, float, int);
	int WriteFLOAT(float, float, int);
	int WriteINT64(long long, int);
	int WriteINT(int, int);
	int WriteSHORT(short, int);
	int WriteSigned(long long, int);
	int WriteUnsigned(unsigned long long, int);
	int WriteVOIDPtr(void *, int);
	int WriteWORD(unsigned short, int);
	~CNWMessage();
	CNWMessage();

};
#endif
