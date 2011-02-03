#include "CPathfindInformation.h"

int CPathfindInformation::ComputeStepTolerance()
{
	asm("leave");
	asm("mov $0x082427a0, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::CreateFirstTileFValueAlternatives(int)
{
	asm("leave");
	asm("mov $0x0824269c, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::DeleteFirstTileFValueAlternatives()
{
	asm("leave");
	asm("mov $0x0824227c, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::FlipStartEndPoints()
{
	asm("leave");
	asm("mov $0x08242724, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::FlipTempEndPoints()
{
	asm("leave");
	asm("mov $0x0824275c, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::GetFirstTileFValueAlternatives(int, int *, int *, CPathfindInfoIntraTileSuccessors **)
{
	asm("leave");
	asm("mov $0x08242628, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::Initialize()
{
	asm("leave");
	asm("mov $0x08241cb4, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::ResetAtEndOfPath()
{
	asm("leave");
	asm("mov $0x082423ac, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::ResetGridSearchData()
{
	asm("leave");
	asm("mov $0x0824251c, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::ResetInterAreaPathSearchData()
{
	asm("leave");
	asm("mov $0x08242494, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::ResetInterAreaSearchData()
{
	asm("leave");
	asm("mov $0x08242430, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::ResetInterTileSearchData()
{
	asm("leave");
	asm("mov $0x082421d4, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::ResetIntraTileSearchData()
{
	asm("leave");
	asm("mov $0x082425c4, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::ResetWayPointData()
{
	asm("leave");
	asm("mov $0x082420ec, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::SetFirstTileFValueAlternatives(int, int, int, CPathfindInfoIntraTileSuccessors *)
{
	asm("leave");
	asm("mov $0x08242664, %eax");
	asm("jmp %eax");
}

int CPathfindInformation::Shutdown()
{
	asm("leave");
	asm("mov $0x08241fc0, %eax");
	asm("jmp %eax");
}

