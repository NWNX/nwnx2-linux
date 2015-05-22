#include "CExoResMan.h"

int CExoResMan::AddEncapsulatedResourceFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b37e4, %eax");
    asm("jmp *%eax");
}

int CExoResMan::AddFixedKeyTableFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b381c, %eax");
    asm("jmp *%eax");
}

int CExoResMan::AddKeyTable(CExoString const &, unsigned long, unsigned char *)
{
    asm("leave");
    asm("mov $0x082aefac, %eax");
    asm("jmp *%eax");
}

int CExoResMan::AddResourceDirectory(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b3838, %eax");
    asm("jmp *%eax");
}

int CExoResMan::AddResourceImageFile(CExoString const &, unsigned char *)
{
    asm("leave");
    asm("mov $0x082b3800, %eax");
    asm("jmp *%eax");
}

int CExoResMan::CancelRequest(CRes *)
{
    asm("leave");
    asm("mov $0x082af2e4, %eax");
    asm("jmp *%eax");
}

int CExoResMan::CleanDirectory(CExoString, int, int)
{
    asm("leave");
    asm("mov $0x082b3ed0, %eax");
    asm("jmp *%eax");
}

int CExoResMan::CreateDirectory(CExoString)
{
    asm("leave");
    asm("mov $0x082b2410, %eax");
    asm("jmp *%eax");
}

void * CExoResMan::Demand(CRes *)
{
    asm("leave");
    asm("mov $0x082af408, %eax");
    asm("jmp *%eax");
}

int CExoResMan::DumpAll()
{
    asm("leave");
    asm("mov $0x082af600, %eax");
    asm("jmp *%eax");
}

int CExoResMan::Dump(CRes *, int)
{
    asm("leave");
    asm("mov $0x082b38fc, %eax");
    asm("jmp *%eax");
}

int CExoResMan::Exists(CResRef const &, unsigned short, unsigned long *)
{
    asm("leave");
    asm("mov $0x082b393c, %eax");
    asm("jmp *%eax");
}

int CExoResMan::FreeChunk()
{
    asm("leave");
    asm("mov $0x082afc7c, %eax");
    asm("jmp *%eax");
}

int CExoResMan::FreeResourceData(CRes *)
{
    asm("leave");
    asm("mov $0x082b3990, %eax");
    asm("jmp *%eax");
}

int CExoResMan::Free(CRes *)
{
    asm("leave");
    asm("mov $0x082afbb8, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetEncapsulatedFileDescription(CExoString const &)
{
    asm("leave");
    asm("mov $0x082afddc, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetFreeDiskSpace(CExoString const &, unsigned long long *)
{
    asm("leave");
    asm("mov $0x082b2278, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetIsStaticType(unsigned short)
{
    asm("leave");
    asm("mov $0x082b3c90, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetKeyEntry(CResRef const &, unsigned short, CExoKeyTable **, CKeyTableEntry **)
{
    asm("leave");
    asm("mov $0x082aff20, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetNewResRef(CResRef const &, unsigned short, CResRef &)
{
    asm("leave");
    asm("mov $0x082af8e0, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetResID(CResRef const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082b3ae4, %eax");
    asm("jmp *%eax");
}

CRes * CExoResMan::GetResObject(CResRef const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082b3a30, %eax");
    asm("jmp *%eax");
}

CExoStringList * CExoResMan::GetResOfType(unsigned short, CRes *)
{
    asm("leave");
    asm("mov $0x082b39f4, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetResOfType(unsigned short, int)
{
    asm("leave");
    asm("mov $0x082b0124, %eax");
    asm("jmp *%eax");
}

void CExoResMan::GetResRefFromFile(CResRef &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082b0450, %eax");
    asm("jmp *%eax");
}

unsigned short CExoResMan::GetResTypeFromFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b056c, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetTableCount(CRes *, int)
{
    asm("leave");
    asm("mov $0x082b0684, %eax");
    asm("jmp *%eax");
}

CExoKeyTable * CExoResMan::GetTable(CRes *)
{
    asm("leave");
    asm("mov $0x082b3b30, %eax");
    asm("jmp *%eax");
}

int CExoResMan::GetTotalPhysicalMemory()
{
    asm("leave");
    asm("mov $0x082b3cb4, %eax");
    asm("jmp *%eax");
}

int CExoResMan::Malloc(CRes *)
{
    asm("leave");
    asm("mov $0x082b3cc0, %eax");
    asm("jmp *%eax");
}

int CExoResMan::NukeDirectory(CExoString, int, int)
{
    asm("leave");
    asm("mov $0x082b3f40, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ReadRaw(CRes *, int, char *)
{
    asm("leave");
    asm("mov $0x082b3e60, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ReleaseResObject(CRes *)
{
    asm("leave");
    asm("mov $0x082b3d48, %eax");
    asm("jmp *%eax");
}

int CExoResMan::Release(CRes *)
{
    asm("leave");
    asm("mov $0x082b075c, %eax");
    asm("jmp *%eax");
}

int CExoResMan::RemoveEncapsulatedResourceFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b3854, %eax");
    asm("jmp *%eax");
}

int CExoResMan::RemoveFile(CExoString const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082b2f1c, %eax");
    asm("jmp *%eax");
}

int CExoResMan::RemoveFixedKeyTableFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b3884, %eax");
    asm("jmp *%eax");
}

int CExoResMan::RemoveFromToBeFreedList(CRes *)
{
    asm("leave");
    asm("mov $0x082b3bec, %eax");
    asm("jmp *%eax");
}

int CExoResMan::RemoveKeyTable(CExoString const &, unsigned long)
{
    asm("leave");
    asm("mov $0x082b0888, %eax");
    asm("jmp *%eax");
}

int CExoResMan::RemoveResourceDirectory(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b389c, %eax");
    asm("jmp *%eax");
}

int CExoResMan::RemoveResourceImageFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b386c, %eax");
    asm("jmp *%eax");
}

int CExoResMan::Request(CRes *)
{
    asm("leave");
    asm("mov $0x082b3db0, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ResumeServicing()
{
    asm("leave");
    asm("mov $0x082b3e00, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceCurrentAsyncRes()
{
    asm("leave");
    asm("mov $0x082b30a0, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceFromDirectoryRaw(CRes *, int, char *)
{
    asm("leave");
    asm("mov $0x082b19b0, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceFromDirectory(CRes *, int)
{
    asm("leave");
    asm("mov $0x082b0970, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceFromEncapsulatedRaw(CRes *, int, char *)
{
    asm("leave");
    asm("mov $0x082b1e38, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceFromEncapsulated(CRes *, int)
{
    asm("leave");
    asm("mov $0x082b1020, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceFromImageRaw(CRes *, int, char *)
{
    asm("leave");
    asm("mov $0x082b20f8, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceFromImage(CRes *, int)
{
    asm("leave");
    asm("mov $0x082b1670, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceFromResFileRaw(CRes *, int, char *)
{
    asm("leave");
    asm("mov $0x082b1fc0, %eax");
    asm("jmp *%eax");
}

int CExoResMan::ServiceFromResFile(CRes *, int)
{
    asm("leave");
    asm("mov $0x082b1330, %eax");
    asm("jmp *%eax");
}

void CExoResMan::SetResObject(CResRef const &, unsigned short, CRes *)
{
    asm("leave");
    asm("mov $0x082b3a80, %eax");
    asm("jmp *%eax");
}

int CExoResMan::SetTotalResourceMemory(int)
{
    asm("leave");
    asm("mov $0x082b3e10, %eax");
    asm("jmp *%eax");
}

int CExoResMan::SuspendServicing()
{
    asm("leave");
    asm("mov $0x082b3e50, %eax");
    asm("jmp *%eax");
}

int CExoResMan::UpdateEncapsulatedResourceFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b38b4, %eax");
    asm("jmp *%eax");
}

int CExoResMan::UpdateFixedKeyTableFile(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b38cc, %eax");
    asm("jmp *%eax");
}

int CExoResMan::UpdateKeyTable(CExoString const &, unsigned long)
{
    asm("leave");
    asm("mov $0x082b1858, %eax");
    asm("jmp *%eax");
}

int CExoResMan::UpdateResourceDirectory(CExoString const &)
{
    asm("leave");
    asm("mov $0x082b38e4, %eax");
    asm("jmp *%eax");
}

int CExoResMan::Update(unsigned long)
{
    asm("leave");
    asm("mov $0x082b1750, %eax");
    asm("jmp *%eax");
}

int CExoResMan::WipeDirectory(CExoString, int, int, int, int)
{
    asm("leave");
    asm("mov $0x082b2560, %eax");
    asm("jmp *%eax");
}

