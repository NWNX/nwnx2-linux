#include "CNWSWaypoint.h"

void CNWSWaypoint::AIUpdate()
{
    asm("leave");
    asm("mov $0x081f5108, %eax");
    asm("jmp *%eax");
}

void CNWSWaypoint::AddToArea(CNWSArea *, float, float, float, int)
{
    asm("leave");
    asm("mov $0x081f505c, %eax");
    asm("jmp *%eax");
}

CNWSWaypoint * CNWSWaypoint::AsNWSWaypoint()
{
    asm("leave");
    asm("mov $0x081f521c, %eax");
    asm("jmp *%eax");
}

void CNWSWaypoint::EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x081f5110, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSWaypoint::GetFirstName()
{
    asm("leave");
    asm("mov $0x081f52d4, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::GetIsMapNote()
{
    asm("leave");
    asm("mov $0x081f5238, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::GetMapNoteEnabled()
{
    asm("leave");
    asm("mov $0x081f525c, %eax");
    asm("jmp *%eax");
}

CExoLocString & CNWSWaypoint::GetMapNoteString()
{
    asm("leave");
    asm("mov $0x081f52c4, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::LoadFromTemplate(CResRef, CExoString *)
{
    asm("leave");
    asm("mov $0x081f47a8, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::LoadWaypoint(CResGFF *, CResStruct *, CExoString *)
{
    asm("leave");
    asm("mov $0x081f4964, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::RemoveFromArea()
{
    asm("leave");
    asm("mov $0x081f5150, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::SaveWaypoint(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x081f4e70, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::SetIsMapNote(int)
{
    asm("leave");
    asm("mov $0x081f5224, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::SetMapNoteEnabled(int)
{
    asm("leave");
    asm("mov $0x081f5248, %eax");
    asm("jmp *%eax");
}

int CNWSWaypoint::SetMapNoteString(CExoLocString)
{
    asm("leave");
    asm("mov $0x081f526c, %eax");
    asm("jmp *%eax");
}

