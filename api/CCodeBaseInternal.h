#ifndef _CCODEBASEINTERNAL_H_
#define _CCODEBASEINTERNAL_H_
#include "nwndef.h"

class CCodeBaseInternal
{
public:
	int AddBinaryData(CExoString &, CExoString &, CExoString &, char, void *, int);
	int AddFloat(CExoString &, CExoString &, CExoString &, float);
	int AddInt(CExoString &, CExoString &, CExoString &, int);
	int AddLocation(CExoString &, CExoString &, CExoString &, CScriptLocation const &);
	int AddString(CExoString &, CExoString &, CExoString &, CExoString &);
	int AddVarEnd(SCodeBaseData *, int);
	int AddVarStart(SCodeBaseData *, CExoString &, CExoString &, int &);
	int AddVector(CExoString &, CExoString &, CExoString &, Vector const &);
	int CloseAllFiles();
	int CloseFile(int);
	int DeleteVar(CExoString &, CExoString &, CExoString &);
	int DestroyDatabase(CExoString &);
	int GetBinaryData(CExoString &, CExoString &, CExoString &, char &, int &);
	int GetFile(CExoString &, int);
	int GetFloat(CExoString &, CExoString &, CExoString &);
	int GetInt(CExoString &, CExoString &, CExoString &);
	int GetLocation(CExoString &, CExoString &, CExoString &);
	int GetString(CExoString &, CExoString &, CExoString &);
	int GetVar(SCodeBaseData *, CExoString &, CExoString &);
	int GetVector(CExoString &, CExoString &, CExoString &);
	int OpenFile(CExoString &, int);
	~CCodeBaseInternal();
	CCodeBaseInternal();

};
#endif
