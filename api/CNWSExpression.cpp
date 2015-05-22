#include "CNWSExpression.h"

void CNWSExpression::ClearAlternate(CNWSExpressionNode *)
{
    asm("leave");
    asm("mov $0x082401cc, %eax");
    asm("jmp *%eax");
}

int CNWSExpression::ClearGraph()
{
    asm("leave");
    asm("mov $0x0824018c, %eax");
    asm("jmp *%eax");
}

CNWSExpressionNode * CNWSExpression::NewNode(int)
{
    asm("leave");
    asm("mov $0x082400cc, %eax");
    asm("jmp *%eax");
}

int CNWSExpression::ParseString(CExoString)
{
    asm("leave");
    asm("mov $0x0823e8a0, %eax");
    asm("jmp *%eax");
}

int CNWSExpression::TestString(CExoString const &, int)
{
    asm("leave");
    asm("mov $0x0823f604, %eax");
    asm("jmp *%eax");
}

