#ifndef _CSCRIPTEVENT_H_
#define _CSCRIPTEVENT_H_
#include "nwndef.h"
#include "CExoString.h"

class CScriptEvent
{
public:
	int CopyScriptEvent(CScriptEvent *);
	int GetFloat(int);
	int GetInteger(int);
	int GetObjectID(int);
	int GetString(int);
	int LoadEvent(CResGFF *, CResStruct *);
	int SaveEvent(CResGFF *, CResStruct *);
	int SetFloat(int, float);
	int SetInteger(int, int);
	int SetObjectID(int, unsigned long);
	int SetString(int, CExoString);
	~CScriptEvent();
	CScriptEvent();
	int operator==(CScriptEvent const &) const;
	int operator!=(CScriptEvent const &) const;

};
#endif
