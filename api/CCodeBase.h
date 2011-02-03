#ifndef _CCODEBASE_H_
#define _CCODEBASE_H_
#include "nwndef.h"

class CCodeBase
{
public:
	int AddBinaryData(CExoString &, CExoString &, CExoString &, char, void *, int);
	int AddFloat(CExoString &, CExoString &, CExoString &, float);
	int AddInt(CExoString &, CExoString &, CExoString &, int);
	int AddLocation(CExoString &, CExoString &, CExoString &, CScriptLocation const &);
	int AddString(CExoString &, CExoString &, CExoString &, CExoString &);
	int AddVector(CExoString &, CExoString &, CExoString &, Vector const &);
	int CloseAllFiles();
	int DeleteVar(CExoString &, CExoString &, CExoString &);
	int DestroyDatabase(CExoString &);
	int GetBinaryData(CExoString &, CExoString &, CExoString &, char &, int &);
	int GetFloat(CExoString &, CExoString &, CExoString &);
	int GetInt(CExoString &, CExoString &, CExoString &);
	int GetLocation(CExoString &, CExoString &, CExoString &);
	int GetString(CExoString &, CExoString &, CExoString &);
	int GetVector(CExoString &, CExoString &, CExoString &);
	~CCodeBase();
	CCodeBase();

};
#endif
