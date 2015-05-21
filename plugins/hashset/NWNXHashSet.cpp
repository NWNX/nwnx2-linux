/***************************************************************************
    NWNXHashSet.cpp - Implementation of the CNWNXHashSet class.
    Copyright (C) 2003 Jeroen Broekhuizen (nwnx@jengine.nl) and
	Ingmar Stieger (Papillon, papillon@blackdagger.com)

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

#include "NWNXHashSet.h"
#include <stdio.h>
#include <memory.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXHashSet::CNWNXHashSet()
{
    iLastOperation = false;
    confKey = "HASHSET";
}

CNWNXHashSet::~CNWNXHashSet()
{
}

bool CNWNXHashSet::OnCreate(gline *config, const char* LogDir)
{
    // call the base class function
    char log[128];
    sprintf(log, "%s/nwnx_hashset.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // if we have plugin specific configuration
    // if(!Configure())
    // return false;

    Log(0, "NWNX HashSet V.1.0\n");
    Log(0, "(c) 2004 by the APS/NWNX Linux Conversion Group\n");
    Log(0, "Based on the Win32 version (c) 2003 by Ingmar Stieger (Papillon)\n");
    Log(0, "visit us at http://www.avlis.org\n\n");
    Log(0, "* Module loaded successfully.\n");

    return true;
}

char* CNWNXHashSet::OnRequest(char* gameObject, char* Request, char* Parameters)
{
    char* presult = NULL;

    Log(2, "Request: \"%s\"\n", Request);
    Log(3, "Params:  \"%s\"\n", Parameters);

    if (strcmp(Request, "LOOKUP") == 0)
        presult = Lookup(gameObject, Parameters);
    else if (strcmp(Request, "INSERT") == 0)
        presult = Insert(gameObject, Parameters);
    else if (strcmp(Request, "DELETE") == 0)
        presult = Delete(gameObject, Parameters);
    else if (strcmp(Request, "STATUS") == 0)
        presult = (char *)(iLastOperation ? "1" : "0");
    else if (strcmp(Request, "VALID") == 0)
        presult = Valid(gameObject, Parameters);
    else if (strcmp(Request, "EXISTS") == 0)
        presult = Exists(gameObject, Parameters);
    else if (strcmp(Request, "GETFIRSTKEY") == 0)
        presult = GetFirstKey(gameObject, Parameters);
    else if (strcmp(Request, "GETNEXTKEY") == 0)
        presult = GetNextKey(gameObject, Parameters);
    else if (strcmp(Request, "GETCURRENTKEY") == 0)
        presult = GetCurrentKey(gameObject, Parameters);
    else if (strcmp(Request, "GETNTHKEY") == 0)
        presult = GetNthKey(gameObject, Parameters);
    else if (strcmp(Request, "HASNEXT") == 0)
        presult = HasNext(gameObject, Parameters);
    else if (strcmp(Request, "GETSIZE") == 0)
        presult = GetSize(gameObject, Parameters);
    else if (strcmp(Request, "DESTROY") == 0)
        presult = Destroy(gameObject, Parameters);
    else if (strcmp(Request, "CREATE") == 0)
        presult = Create(gameObject, Parameters);

    Log(4, "hashset returns[%s]\n", presult);

    // a return value of NULL tells NWNX that it shouldn't copy
    // any values, a non zero pointer tells NWNX that it should copy
    // the null terminated string pointed to by that pointer back into NWN.
    return presult;
}

bool CNWNXHashSet::OnRelease()
{
    // call base class
    return CNWNXBase::OnRelease();
}

char *CNWNXHashSet::GetSeparatedArg(char *pCur, string &arg)
{
    char *pSep;

    // look for a separator
    if ((pSep = strchr(pCur, '!')) != NULL) * pSep = 0;

    // extract the Name
    arg = pCur;

    // if we found a sep, set it back
    if (pSep) {
        *pSep = '!';
        ++pSep;
    }

    return pSep;
}

bool CNWNXHashSet::ParseParam(char *gameObj, char *Param, string &Name, string *Key, string *Value)
{
    unsigned long iGameObjectId = *(unsigned long*)(gameObj + 4);
    string setname;
    char *pSep, oid[10];

    // assume the worst
    iLastOperation = false;

    if (gameObj == NULL || Param == NULL)
        return false;

    // extract the pieces from Param
    pSep = GetSeparatedArg(Param, setname);

    // extract the Key (if the container isn't NULL)
    if (Key != NULL) {
        // fail if we didn't see the separator
        if (pSep == NULL) return false;

        pSep = GetSeparatedArg(pSep, *Key);
    }

    // extract the Value (if the container isn't NULL)
    if (Value != NULL) {
        // fail if we didn't see the separator
        if (pSep == NULL) return false;

        pSep = GetSeparatedArg(pSep, *Value);
    }

    // assemble the real setname
    sprintf(oid, "%08lx-", iGameObjectId);
    Name = oid;
    Name += setname;

    // flag success
    iLastOperation = true;

    // tell the world
    return true;
}

bool CNWNXHashSet::ParseParam(char *gameObj, char *Param, string &Name, string &Key, int &Value)
{
    string aval;

    // iLastOp set by ParseParam, string value version
    if (ParseParam(gameObj, Param, Name, Key, aval)) {
        Value = atoi(aval.c_str());
    }

    return iLastOperation;
}

bool CNWNXHashSet::ParseParam(char *gameObj, char *Param, string &Name, int &Value)
{
    string aval;

    // iLastOp set by ParseParam, string value version
    if (ParseParam(gameObj, Param, Name, aval)) {
        Value = atoi(aval.c_str());
    }

    return iLastOperation;
}

char* CNWNXHashSet::Create(char* gameObject, char* Parameters)
{
    string name;
    int value;
    if (!ParseParam(gameObject, Parameters, name, value))
        return NULL;

    // alakazam!
    HashSets[name];

    return NULL;
}

char* CNWNXHashSet::Destroy(char* gameObject, char* Parameters)
{
    string name;
    if (!ParseParam(gameObject, Parameters, name))
        return NULL;

    if (HashSets.find(name) != HashSets.end()) {
        HashSets.erase(name);
    } else {
        iLastOperation = false;
    }

    return NULL;
}

char* CNWNXHashSet::Insert(char* gameObject, char* Parameters)
{
    string name, key, value;
    if (!ParseParam(gameObject, Parameters, name, key, value))
        return NULL;

    HashSets[name].hashset[key] = value;

    return NULL;
}

char* CNWNXHashSet::Delete(char* gameObject, char* Parameters)
{
    string name, key;
    if (!ParseParam(gameObject, Parameters, name, key))
        return NULL;

    HashSets[name].hashset.erase(key);

    return NULL;
}

char* CNWNXHashSet::Lookup(char* gameObject, char* Parameters)
{
    string name, key;
    if (!ParseParam(gameObject, Parameters, name, key))
        return "";

    if (HashSets.find(name) == HashSets.end() ||
            HashSets[name].hashset.find(key) == HashSets[name].hashset.end()) {
        iLastOperation = false;
        return "";
    }

    return (char*)(HashSets[name].hashset[key].c_str());
}

char* CNWNXHashSet::Valid(char* gameObject, char* Parameters)
{
    string name, key;
    if (!ParseParam(gameObject, Parameters, name, key))
        return "0";

    // does hashset exist
    if (HashSets.find(name) == HashSets.end()) {
        return "0";
    }

    return "1";
}

char* CNWNXHashSet::Exists(char* gameObject, char* Parameters)
{
    string name, key;
    if (!ParseParam(gameObject, Parameters, name, key))
        return "0";

    // does hashset and key exist
    if (HashSets.find(name) == HashSets.end() ||
            HashSets[name].hashset.find(key) == HashSets[name].hashset.end()) {
        return "0";
    }

    return "1";
}

char* CNWNXHashSet::GetSize(char* gameObject, char* Parameters)
{
    string name;
    static char sizebuf[16];

    if (!ParseParam(gameObject, Parameters, name))
        return "0";

    // does hashset exist
    if (HashSets.find(name) == HashSets.end()) {
        iLastOperation = false;
        return "0";
    }

    sprintf(sizebuf, "%d", HashSets[name].hashset.size());

    return sizebuf;
}

char* CNWNXHashSet::GetFirstKey(char* gameObject, char* Parameters)
{
    string name;
    if (!ParseParam(gameObject, Parameters, name))
        return "";

    // does hashset exist
    if (HashSets.find(name) == HashSets.end()) {
        iLastOperation = false;
        return "";
    }

    HashSet *pSet = &(HashSets[name]);
    pSet->p = pSet->hashset.begin();

    if (pSet->p == pSet->hashset.end())
        return "";

    return (char*)(pSet->p->first.c_str());
}

char* CNWNXHashSet::GetNextKey(char* gameObject, char* Parameters)
{
    string name;
    if (!ParseParam(gameObject, Parameters, name))
        return "";

    // does hashset exist
    if (HashSets.find(name) == HashSets.end()) {
        iLastOperation = false;
        return "";
    }

    HashSet *pSet = &(HashSets[name]);
    if (pSet->p == pSet->hashset.end() || (++(pSet->p)) == pSet->hashset.end())
        return "";

    return (char*)(pSet->p->first.c_str());
}

char* CNWNXHashSet::GetCurrentKey(char* gameObject, char* Parameters)
{
    string name;
    if (!ParseParam(gameObject, Parameters, name))
        return "";

    // does hashset exist
    if (HashSets.find(name) == HashSets.end()) {
        iLastOperation = false;
        return "";
    }

    HashSet *pSet = &(HashSets[name]);
    if (pSet->p == pSet->hashset.end())
        return "";

    return (char*)(pSet->p->first.c_str());
}

char* CNWNXHashSet::GetNthKey(char* gameObject, char* Parameters)
{
    string name;
    int value;
    if (!ParseParam(gameObject, Parameters, name, value))
        return NULL;

    Log(0, "Ack! GetNthKey called!\n");

    return "";
}

char* CNWNXHashSet::HasNext(char* gameObject, char* Parameters)
{
    string name;
    if (!ParseParam(gameObject, Parameters, name))
        return "0";

    // does hashset exist
    if (HashSets.find(name) == HashSets.end()) {
        iLastOperation = false;
        return "0";
    }

    HashSet *pSet = &(HashSets[name]);
    StringMap::iterator p = pSet->p;

    if (p == pSet->hashset.end() || (++p) == pSet->hashset.end())
        return "0";

    return "1";
}


