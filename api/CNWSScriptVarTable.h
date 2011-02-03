#ifndef _CNWSSCRIPTVARTABLE_H_
#define _CNWSSCRIPTVARTABLE_H_
#include "nwndef.h"
#include "CScriptLocation.h"

class CNWSScriptVarTable
{
public:
	int DeleteIndex(CExoString &, unsigned long);
	int DestroyFloat(CExoString &);
	int DestroyInt(CExoString &);
	int DestroyLocation(CExoString &);
	int DestroyObject(CExoString &);
	int DestroyString(CExoString &);
	int GetFloat(CExoString &);
	int GetInt(CExoString &);
	int GetLocation(CExoString &);
	int GetObject(CExoString &);
	int GetString(CExoString &);
	int LoadVarTable(CResGFF *, CResStruct *);
	int MatchIndex(CExoString &, unsigned long, int);
	int SaveVarTable(CResGFF *, CResStruct *);
	int SetFloat(CExoString &, float);
	int SetInt(CExoString &, int, int);
	int SetLocation(CExoString &, CScriptLocation);
	int SetObject(CExoString &, unsigned long);
	int SetString(CExoString &, CExoString &);
	~CNWSScriptVarTable();

};
#endif
