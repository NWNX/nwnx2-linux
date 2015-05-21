#include "CResGFF.h"

unsigned char * CResGFF::AddDataField(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082bb654, %eax");
    asm("jmp *%eax");
}

unsigned char * CResGFF::AddDataLayoutField(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082b93e8, %eax");
    asm("jmp *%eax");
}

unsigned char * CResGFF::AddDataLayoutList(unsigned long, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x082b94a8, %eax");
    asm("jmp *%eax");
}

CResGFFField * CResGFF::AddField(CResStruct *, char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082b9164, %eax");
    asm("jmp *%eax");
}

unsigned long CResGFF::AddLabel(char *)
{
    asm("leave");
    asm("mov $0x082b92e0, %eax");
    asm("jmp *%eax");
}

int CResGFF::AddListElement(CResStruct *, CResList *, unsigned long)
{
    asm("leave");
    asm("mov $0x082b9e50, %eax");
    asm("jmp *%eax");
}

int CResGFF::AddList(CResList *, CResStruct *, char *)
{
    asm("leave");
    asm("mov $0x082bbfd8, %eax");
    asm("jmp *%eax");
}

int CResGFF::AddStructToStruct(CResStruct *, CResStruct *, char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082bc078, %eax");
    asm("jmp *%eax");
}

unsigned long CResGFF::AddStruct(unsigned long)
{
    asm("leave");
    asm("mov $0x082b90a8, %eax");
    asm("jmp *%eax");
}

int CResGFF::CreateGFFFile(CResStruct *, CExoString const &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082baac4, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetDataFieldNum()
{
    asm("leave");
    asm("mov $0x082bc6b8, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetDataField(CResGFFField *, unsigned long &)
{
    asm("leave");
    asm("mov $0x082bb588, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetDataFromPointer(void *, int)
{
    asm("leave");
    asm("mov $0x082b961c, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetDataLayoutFieldNum()
{
    asm("leave");
    asm("mov $0x082bc6cc, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetDataLayoutField(CResGFFField *, unsigned long &)
{
    asm("leave");
    asm("mov $0x082bb5c0, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetDataLayoutListNum()
{
    asm("leave");
    asm("mov $0x082bc6e0, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetDataLayoutList(CResGFFField *, unsigned long &)
{
    asm("leave");
    asm("mov $0x082bb5f8, %eax");
    asm("jmp *%eax");
}

unsigned long CResGFF::GetElementType(CResStruct *)
{
    asm("leave");
    asm("mov $0x082bb760, %eax");
    asm("jmp *%eax");
}

unsigned long CResGFF::GetFieldByLabel(CResStruct *, char *)
{
    asm("leave");
    asm("mov $0x082b8b9c, %eax");
    asm("jmp *%eax");
}

unsigned long CResGFF::GetFieldCount(CResStruct *)
{
    asm("leave");
    asm("mov $0x082bb7b8, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetFieldCount(CResGFFStruct *)
{
    asm("leave");
    asm("mov $0x082bb79c, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetFieldLabel(CResStruct *, unsigned long)
{
    asm("leave");
    asm("mov $0x082bb838, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetFieldNum()
{
    asm("leave");
    asm("mov $0x082bc690, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetFieldSize(CResStruct *, char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082b9860, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetFieldStringID(CResStruct *, unsigned long)
{
    asm("leave");
    asm("mov $0x082bb888, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetFieldType(CResStruct *, char *, unsigned long)
{
    asm("leave");
    asm("mov $0x082bb7f4, %eax");
    asm("jmp *%eax");
}

CResGFFField * CResGFF::GetField(CResStruct *, unsigned long)
{
    asm("leave");
    asm("mov $0x082b8af8, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetField(CResGFFStruct *, unsigned long)
{
    asm("leave");
    asm("mov $0x082bc708, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetFileData(char *)
{
    asm("leave");
    asm("mov $0x082b9568, %eax");
    asm("jmp *%eax");
}

void CResGFF::GetGFFFileInfo(CExoString *, CExoString *)
{
    asm("leave");
    asm("mov $0x082bb70c, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetLabelNum()
{
    asm("leave");
    asm("mov $0x082bc6a4, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetLabel(CResStruct *, unsigned long)
{
    asm("leave");
    asm("mov $0x082bb544, %eax");
    asm("jmp *%eax");
}

unsigned long CResGFF::GetListCount(CResList *)
{
    asm("leave");
    asm("mov $0x082bb990, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetListElement(CResStruct *, CResList *, unsigned long)
{
    asm("leave");
    asm("mov $0x082b9940, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetList(CResList *, CResStruct *, char *)
{
    asm("leave");
    asm("mov $0x082bb8f4, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetStructFromStruct(CResStruct *, CResStruct *, char *)
{
    asm("leave");
    asm("mov $0x082bba00, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetStructNum()
{
    asm("leave");
    asm("mov $0x082bc67c, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetStruct(CResStruct *)
{
    asm("leave");
    asm("mov $0x082bb510, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetTopLevelStruct(CResStruct *)
{
    asm("leave");
    asm("mov $0x082bba5c, %eax");
    asm("jmp *%eax");
}

unsigned long CResGFF::GetTotalSize()
{
    asm("leave");
    asm("mov $0x082bc5c4, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetWastedFieldSpace()
{
    asm("leave");
    asm("mov $0x082bc660, %eax");
    asm("jmp *%eax");
}

int CResGFF::GetWastedListSpace()
{
    asm("leave");
    asm("mov $0x082bc66c, %eax");
    asm("jmp *%eax");
}

void CResGFF::InitializeForWriting()
{
    asm("leave");
    asm("mov $0x082b8d08, %eax");
    asm("jmp *%eax");
}

int CResGFF::IsDataInPlace(unsigned long)
{
    asm("leave");
    asm("mov $0x082bb630, %eax");
    asm("jmp *%eax");
}

int CResGFF::IsLoaded()
{
    asm("leave");
    asm("mov $0x082bc650, %eax");
    asm("jmp *%eax");
}

int CResGFF::OnResourceFreed()
{
    asm("leave");
    asm("mov $0x082bb3f8, %eax");
    asm("jmp *%eax");
}

int CResGFF::OnResourceServiced()
{
    asm("leave");
    asm("mov $0x082b8708, %eax");
    asm("jmp *%eax");
}

void CResGFF::Pack(unsigned char, unsigned long)
{
    asm("leave");
    asm("mov $0x082bb120, %eax");
    asm("jmp *%eax");
}

unsigned char CResGFF::ReadFieldBYTE(CResStruct *, char *, int &, unsigned char)
{
    asm("leave");
    asm("mov $0x082bba7c, %eax");
    asm("jmp *%eax");
}

CExoLocString CResGFF::ReadFieldCExoLocString(CResStruct *, char *, int &, CExoLocString const &)
{
    asm("leave");
    asm("mov $0x082b9ba8, %eax");
    asm("jmp *%eax");
}

CExoString CResGFF::ReadFieldCExoString(CResStruct *, char *, int &, CExoString const &)
{
    asm("leave");
    asm("mov $0x082b9aac, %eax");
    asm("jmp *%eax");
}

char CResGFF::ReadFieldCHAR(CResStruct *, char *, int &, char)
{
    asm("leave");
    asm("mov $0x082bbadc, %eax");
    asm("jmp *%eax");
}

CResRef CResGFF::ReadFieldCResRef(CResStruct *, char *, int &, CResRef const &)
{
    asm("leave");
    asm("mov $0x082b99dc, %eax");
    asm("jmp *%eax");
}

int CResGFF::ReadFieldDOUBLE(CResStruct *, char *, int &, double)
{
    asm("leave");
    asm("mov $0x082bbe68, %eax");
    asm("jmp *%eax");
}

int CResGFF::ReadFieldDWORD64(CResStruct *, char *, int &, unsigned long long)
{
    asm("leave");
    asm("mov $0x082bbd10, %eax");
    asm("jmp *%eax");
}

unsigned long CResGFF::ReadFieldDWORD(CResStruct *, char *, int &, unsigned long)
{
    asm("leave");
    asm("mov $0x082bbbfc, %eax");
    asm("jmp *%eax");
}

float CResGFF::ReadFieldFLOAT(CResStruct *, char *, int &, float)
{
    asm("leave");
    asm("mov $0x082bbcb4, %eax");
    asm("jmp *%eax");
}

int CResGFF::ReadFieldINT64(CResStruct *, char *, int &, long long)
{
    asm("leave");
    asm("mov $0x082bbdbc, %eax");
    asm("jmp *%eax");
}

int CResGFF::ReadFieldINT(CResStruct *, char *, int &, int)
{
    asm("leave");
    asm("mov $0x082bbc58, %eax");
    asm("jmp *%eax");
}

short CResGFF::ReadFieldSHORT(CResStruct *, char *, int &, short)
{
    asm("leave");
    asm("mov $0x082bbb9c, %eax");
    asm("jmp *%eax");
}

void * CResGFF::ReadFieldVOID(CResStruct *, void *, unsigned long, char *, int &, void *)
{
    asm("leave");
    asm("mov $0x082bbf1c, %eax");
    asm("jmp *%eax");
}

unsigned short CResGFF::ReadFieldWORD(CResStruct *, char *, int &, unsigned short)
{
    asm("leave");
    asm("mov $0x082bbb3c, %eax");
    asm("jmp *%eax");
}

void CResGFF::ReleaseResource()
{
    asm("leave");
    asm("mov $0x082bb454, %eax");
    asm("jmp *%eax");
}

int CResGFF::SetFileType(char *)
{
    asm("leave");
    asm("mov $0x082bc630, %eax");
    asm("jmp *%eax");
}

int CResGFF::SetReplaceExistingFields(int)
{
    asm("leave");
    asm("mov $0x082bc6f4, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldBYTE(CResStruct *, unsigned char, char *)
{
    asm("leave");
    asm("mov $0x082bc0f4, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldCExoLocString(CResStruct *, CExoLocString, char *)
{
    asm("leave");
    asm("mov $0x082ba650, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldCExoString(CResStruct *, CExoString const &, char *)
{
    asm("leave");
    asm("mov $0x082ba4ec, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldCHAR(CResStruct *, char, char *)
{
    asm("leave");
    asm("mov $0x082bc184, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldCResRef(CResStruct *, CResRef const &, char *)
{
    asm("leave");
    asm("mov $0x082ba368, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldDOUBLE(CResStruct *, double, char *)
{
    asm("leave");
    asm("mov $0x082ba20c, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldDWORD64(CResStruct *, unsigned long long, char *)
{
    asm("leave");
    asm("mov $0x082b9f4c, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldDWORD(CResStruct *, unsigned long, char *)
{
    asm("leave");
    asm("mov $0x082bc334, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldFLOAT(CResStruct *, float, char *)
{
    asm("leave");
    asm("mov $0x082bc444, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldINT64(CResStruct *, long long, char *)
{
    asm("leave");
    asm("mov $0x082ba0ac, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldINT(CResStruct *, int, char *)
{
    asm("leave");
    asm("mov $0x082bc3bc, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldSHORT(CResStruct *, short, char *)
{
    asm("leave");
    asm("mov $0x082bc2a4, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldVOID(CResStruct *, void const *, unsigned long, char *)
{
    asm("leave");
    asm("mov $0x082ba9b0, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteFieldWORD(CResStruct *, unsigned short, char *)
{
    asm("leave");
    asm("mov $0x082bc214, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteGFFData(CExoFile &, unsigned long &)
{
    asm("leave");
    asm("mov $0x082bad2c, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteGFFFile(char *)
{
    asm("leave");
    asm("mov $0x082bafcc, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteGFFFile(CExoString const &, unsigned short)
{
    asm("leave");
    asm("mov $0x082bc4cc, %eax");
    asm("jmp *%eax");
}

int CResGFF::WriteGFFToPointer(void **, int &)
{
    asm("leave");
    asm("mov $0x082bae78, %eax");
    asm("jmp *%eax");
}

