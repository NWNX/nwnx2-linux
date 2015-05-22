#ifndef _CEXONETEXTENDABLEBUFFER_H_
#define _CEXONETEXTENDABLEBUFFER_H_
#include "nwndef.h"

class CExoNetExtendableBuffer
{
public:
    unsigned long ChangeFrameReference(unsigned short, int, int);
    int GetCurrentUsage(unsigned long *, unsigned long *);
    unsigned short GetFirstUsedFrame(int);
    int GetFrameConnectionId(unsigned short, int);
    int GetFrameData(unsigned short, unsigned char **, unsigned long *, unsigned long *, unsigned short *, int);
    unsigned char * GetFramePointer(unsigned short, int);
    int GetFrameSize(unsigned short, int);
    int GetMaximumUsage(unsigned long *, unsigned long *);
    unsigned short GetUnusedFrame(int);
    int LockExtBufferInstance();
    int SetFrameData(unsigned short, unsigned char *, unsigned long, unsigned long, unsigned long, int);
    int UnlockExtBufferInstance();
    ~CExoNetExtendableBuffer();
    CExoNetExtendableBuffer();

};
#endif
