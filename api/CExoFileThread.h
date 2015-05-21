#ifndef _CEXOFILETHREAD_H_
#define _CEXOFILETHREAD_H_
#include "nwndef.h"

class CExoFileThread
{
public:
    int AsyncRead();
    int Read(void *, unsigned long, unsigned long, _IO_FILE *);
    ~CExoFileThread();
    CExoFileThread();

};
#endif
