#include "CAppManager.h"

void CAppManager::CreateServer()
{
    asm("leave");
    asm("mov $0x08052318, %eax");
    asm("jmp *%eax");
}

void CAppManager::DestroyScriptDebuggerPopup()
{
    asm("leave");
    asm("mov $0x080523f4, %eax");
    asm("jmp *%eax");
}

void CAppManager::DestroyServer()
{
    asm("leave");
    asm("mov $0x08052388, %eax");
    asm("jmp *%eax");
}

void CAppManager::DisplayScriptDebuggerPopup()
{
    asm("leave");
    asm("mov $0x080523ec, %eax");
    asm("jmp *%eax");
}

void CAppManager::DoSaveGameScreenShot(CExoString &)
{
    asm("leave");
    asm("mov $0x08052308, %eax");
    asm("jmp *%eax");
}

int CAppManager::GetDungeonMasterEXERunning()
{
    asm("leave");
    asm("mov $0x080523e0, %eax");
    asm("jmp *%eax");
}

CObjectTableManager * CAppManager::GetObjectTableManager(unsigned long)
{
    asm("leave");
    asm("mov $0x080522e8, %eax");
    asm("jmp *%eax");
}

unsigned char CAppManager::GetProgressFromCodeword(CExoString &)
{
    asm("leave");
    asm("mov $0x08051e2c, %eax");
    asm("jmp *%eax");
}

unsigned char CAppManager::ReadProgressFromINI(unsigned char)
{
    asm("leave");
    asm("mov $0x080515c0, %eax");
    asm("jmp *%eax");
}

int CAppManager::SetDungeonMasterEXERunning(int)
{
    asm("leave");
    asm("mov $0x080523d0, %eax");
    asm("jmp *%eax");
}

int CAppManager::ShowServerMem()
{
    asm("leave");
    asm("mov $0x08052310, %eax");
    asm("jmp *%eax");
}

int CAppManager::SpawnExternalScriptDebugger()
{
    asm("leave");
    asm("mov $0x080523fc, %eax");
    asm("jmp *%eax");
}

