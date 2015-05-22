#include "CServerAIEventNode.h"

int CServerAIEventNode::LoadNode(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x08097a4c, %eax");
    asm("jmp *%eax");
}

int CServerAIEventNode::SaveNode(CResGFF *, CResStruct *)
{
    asm("leave");
    asm("mov $0x0809774c, %eax");
    asm("jmp *%eax");
}

