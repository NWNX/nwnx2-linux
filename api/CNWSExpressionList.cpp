#include "CNWSExpressionList.h"

int CNWSExpressionList::AddNodeToHead(CNWSExpressionNode *)
{
    asm("leave");
    asm("mov $0x08240094, %eax");
    asm("jmp *%eax");
}

void CNWSExpressionList::AddNode(CNWSExpressionNode *)
{
    asm("leave");
    asm("mov $0x08240050, %eax");
    asm("jmp *%eax");
}

void CNWSExpressionList::DeleteAlternate(CNWSExpressionNode *)
{
    asm("leave");
    asm("mov $0x0823ffe8, %eax");
    asm("jmp *%eax");
}

int CNWSExpressionList::DeleteList()
{
    asm("leave");
    asm("mov $0x0823ff90, %eax");
    asm("jmp *%eax");
}

