#ifndef _CEXONETFRAMEBUFFER_H_
#define _CEXONETFRAMEBUFFER_H_
#include "nwndef.h"

class CExoNetFrameBuffer
{
public:
    unsigned long ChangeRefCount(unsigned char, int);
    int GetFrameConnectionId(unsigned char);
    int GetFrameData(unsigned char, unsigned char **, unsigned long *, unsigned long *, unsigned char *);
    int GetFramePointer(unsigned char);
    int GetFrameSize(unsigned char);
    int GetRefCount(unsigned char);
    int GetUnusedFrame();
    int GetUsedFrame();
    int SetFrameData(unsigned char, unsigned char *, unsigned long, unsigned long, unsigned long);
    ~CExoNetFrameBuffer();
    CExoNetFrameBuffer();

};
#endif
