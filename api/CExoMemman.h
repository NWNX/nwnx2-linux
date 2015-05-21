#ifndef _CEXOMEMMAN_H_
#define _CEXOMEMMAN_H_
#include "nwndef.h"

class CExoMemman
{
public:
    int AddFreeRecord(unsigned long);
    int Alloc(unsigned long, int);
    int CheckHeaps();
    void Clear();
    int Destroy();
    int DoHeapWalk();
    int FillRecordPtrArray();
    int FinalReport();
    int Free(void *);
    int GetFreeRecord();
    int GetHeaps();
    void OutputTypeTrackingReport();
    int PopType(unsigned long);
    int PushType(unsigned long);
    int ReportEntry(CMemRecord &);
    int ReportRemoval(CMemRecord &, int);
    int SnapShotReportPrint();
    int SnapShotReportWithSort();
    int StartReport();

};
#endif
