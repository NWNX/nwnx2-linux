#include "CNWSDialog.h"

void CNWSDialog::AddJournalEntry(CExoString const &, unsigned long, unsigned long)
{
    asm("leave");
    asm("mov $0x0823ceec, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::CheckScript(CNWSObject *, CResRef const &)
{
    asm("leave");
    asm("mov $0x0823cab0, %eax");
    asm("jmp *%eax");
}

void CNWSDialog::Cleanup()
{
    asm("leave");
    asm("mov $0x0823ada4, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::ClearDialogOwnerInObject(unsigned long)
{
    asm("leave");
    asm("mov $0x0823e520, %eax");
    asm("jmp *%eax");
}

CNWSObject * CNWSDialog::GetSpeaker(CNWSObject *, CExoString const &)
{
    asm("leave");
    asm("mov $0x0823c5e4, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::GetStartEntryOneLiner(CNWSObject *, CExoLocString &, CResRef &, CResRef &)
{
    asm("leave");
    asm("mov $0x0823cc78, %eax");
    asm("jmp *%eax");
}

unsigned long CNWSDialog::GetStartEntry(CNWSObject *)
{
    asm("leave");
    asm("mov $0x0823cb94, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::HandleReply(unsigned long, CNWSObject *, unsigned long, int, unsigned long)
{
    asm("leave");
    asm("mov $0x0823deac, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::IsPlayerInDialog(unsigned long)
{
    asm("leave");
    asm("mov $0x0823e598, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::LoadDialog(CResGFF *, int)
{
    asm("leave");
    asm("mov $0x0823b268, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::RemovePlayer(unsigned long)
{
    asm("leave");
    asm("mov $0x0823c4f0, %eax");
    asm("jmp *%eax");
}

void CNWSDialog::RunScript(CNWSObject *, CResRef const &)
{
    asm("leave");
    asm("mov $0x0823e5f0, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::SendDialogEntry(CNWSObject *, unsigned long, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0823d238, %eax");
    asm("jmp *%eax");
}

int CNWSDialog::SendDialogReplies(CNWSObject *, unsigned long)
{
    asm("leave");
    asm("mov $0x0823d85c, %eax");
    asm("jmp *%eax");
}

float CNWSDialog::SetDialogDelay(CNWSObject *, CExoLocString, unsigned long, int)
{
    asm("leave");
    asm("mov $0x0823cd70, %eax");
    asm("jmp *%eax");
}

