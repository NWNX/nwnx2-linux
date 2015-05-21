#include "CExoMemman.h"

int CExoMemman::AddFreeRecord(unsigned long)
{
    asm("leave");
    asm("mov $0x082ae884, %eax");
    asm("jmp *%eax");
}

int CExoMemman::Alloc(unsigned long, int)
{
    asm("leave");
    asm("mov $0x082adea8, %eax");
    asm("jmp *%eax");
}

int CExoMemman::CheckHeaps()
{
    asm("leave");
    asm("mov $0x082ae660, %eax");
    asm("jmp *%eax");
}

void CExoMemman::Clear()
{
    asm("leave");
    asm("mov $0x082adbf4, %eax");
    asm("jmp *%eax");
}

int CExoMemman::Destroy()
{
    asm("leave");
    asm("mov $0x082ae64c, %eax");
    asm("jmp *%eax");
}

int CExoMemman::DoHeapWalk()
{
    asm("leave");
    asm("mov $0x082adcd4, %eax");
    asm("jmp *%eax");
}

int CExoMemman::FillRecordPtrArray()
{
    asm("leave");
    asm("mov $0x082ae928, %eax");
    asm("jmp *%eax");
}

int CExoMemman::FinalReport()
{
    asm("leave");
    asm("mov $0x082ae1c8, %eax");
    asm("jmp *%eax");
}

int CExoMemman::Free(void *)
{
    asm("leave");
    asm("mov $0x082ae668, %eax");
    asm("jmp *%eax");
}

int CExoMemman::GetFreeRecord()
{
    asm("leave");
    asm("mov $0x082ae868, %eax");
    asm("jmp *%eax");
}

int CExoMemman::GetHeaps()
{
    asm("leave");
    asm("mov $0x082ae658, %eax");
    asm("jmp *%eax");
}

void CExoMemman::OutputTypeTrackingReport()
{
    asm("leave");
    asm("mov $0x082ae298, %eax");
    asm("jmp *%eax");
}

int CExoMemman::PopType(unsigned long)
{
    asm("leave");
    asm("mov $0x082ae788, %eax");
    asm("jmp *%eax");
}

int CExoMemman::PushType(unsigned long)
{
    asm("leave");
    asm("mov $0x082ae750, %eax");
    asm("jmp *%eax");
}

int CExoMemman::ReportEntry(CMemRecord &)
{
    asm("leave");
    asm("mov $0x082adfe4, %eax");
    asm("jmp *%eax");
}

int CExoMemman::ReportRemoval(CMemRecord &, int)
{
    asm("leave");
    asm("mov $0x082ae0cc, %eax");
    asm("jmp *%eax");
}

int CExoMemman::SnapShotReportPrint()
{
    asm("leave");
    asm("mov $0x082ae368, %eax");
    asm("jmp *%eax");
}

int CExoMemman::SnapShotReportWithSort()
{
    asm("leave");
    asm("mov $0x082ae8f0, %eax");
    asm("jmp *%eax");
}

int CExoMemman::StartReport()
{
    asm("leave");
    asm("mov $0x082ae7b8, %eax");
    asm("jmp *%eax");
}

