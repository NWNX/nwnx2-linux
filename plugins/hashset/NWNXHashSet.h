/***************************************************************************
NWNXHashSet.h - Interface for the CNWNXHashSet class.
Copyright (C) 2003 Jeroen Broekhuizen (nwnx@jengine.nl)

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
***************************************************************************/

#ifndef NWNXHashSet_H_
#define NWNXHashSet_H_

#include <map>
#include <string>
using namespace std;

#include "NWNXBase.h"

// StringMap typedef comes from gline ~ map<string,string>
struct HashSet {
    StringMap hashset;
    StringMap::iterator p;
};

typedef map< string, HashSet, less<string> > HashTable;

class CNWNXHashSet : public CNWNXBase
{
public:
    CNWNXHashSet();
    virtual ~CNWNXHashSet();

    bool OnCreate(gline *nwnxConfig, const char* LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();

protected:
    char* GetSeparatedArg(char *pCur, string &arg);

    bool ParseParam(char *gameObj, char *Param,
                    string &Name, string *Key = NULL, string *Value = NULL);
    bool ParseParam(char *gameObj, char *Param, string &Name, string &Key) {
        return ParseParam(gameObj, Param, Name, &Key);
    }
    bool ParseParam(char *gameObj, char *Param, string &Name, string &Key, string &Value) {
        return ParseParam(gameObj, Param, Name, &Key, &Value);
    }
    bool ParseParam(char *gameObj, char *Param,
                    string &Name, string &Key, int &Value);
    bool ParseParam(char *gameObj, char *Param,
                    string &Name, int &Value);

    char* Create(char* gameObject, char* Parameters);
    char* Destroy(char* gameObject, char* Parameters);
    char* Insert(char* gameObject, char* Parameters);
    char* Delete(char* gameObject, char* Parameters);
    char* Lookup(char* gameObject, char* Parameters);
    char* Valid(char* gameObject, char* Parameters);
    char* Exists(char* gameObject, char* Parameters);
    char* GetFirstKey(char* gameObject, char* Parameters);
    char* GetNextKey(char* gameObject, char* Parameters);
    char* GetCurrentKey(char* gameObject, char* Parameters);
    char* GetNthKey(char* gameObject, char* Parameters);
    char* GetSize(char* gameObject, char* Parameters);
    char* HasNext(char* gameObject, char* Parameters);

private:
    bool iLastOperation;
    HashTable HashSets;
};

#endif
