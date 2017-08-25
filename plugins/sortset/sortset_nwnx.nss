// Name     : sortset_nwnx.nss
// Purpose  : A general purpose implementation of a sortable set (NWNX version)
// Author   : John Klar
// Modified : December 18, 2003

// This file is licensed under the terms of the
// GNU GENERAL PUBLIC LICENSE (GPL) Version 2


void SortSetInit(object oTgt, string setkey);
void SortSetSort(object oTgt, string setkey);
int SortSetExists(object oTgt, string setkey, string dbkey);
int SortSetLength(object oTgt, string setkey);
int SortSetAdd(object oTgt, string setkey, string dbkey, string sortkey, string value);
int SortSetSetByTag(object oTgt, string setkey, string dbkey, string sortkey, string value);
int SortSetSetByIdx(object oTgt, string setkey, int index, string sortkey, string value);
string SortSetGetByTag(object oTgt, string setkey, string dbkey);
string SortSetGetByIdx(object oTgt, string setkey, int index);
int SortSetRemoveByIdx(object oTgt, string setkey, int index);
int SortSetDestroy(object oTgt, string setkey);

// 256 spaces
string sspad = "                                "+
               "                                "+
               "                                "+
               "                                "+
               "                                "+
               "                                "+
               "                                "+
               "                                ";

string SortSetCmd(object oTgt, string setkey, string cmd) {
    string key = "NWNX!SORTSET!"+setkey;
    SetLocalString(oTgt,key,cmd+"!"+sspad);
    return GetLocalString(oTgt,key);
}

void SortSetInit(object oTgt, string setkey) {
    SortSetCmd(oTgt,setkey,"INIT");
}

void SortSetSort(object oTgt, string setkey) {
    SortSetCmd(oTgt,setkey,"SORT");
}

int SortSetExists(object oTgt, string setkey, string dbkey) {
    return StringToInt(SortSetCmd(oTgt,setkey,"EXISTS!"+dbkey));
}

int SortSetLength(object oTgt, string setkey) {
    return StringToInt(SortSetCmd(oTgt,setkey,"LENGTH"));
}

int SortSetAdd(object oTgt, string setkey, string dbkey, string sortkey, string value) {
    return StringToInt(SortSetCmd(oTgt,setkey,"ADD!"+dbkey+"!"+sortkey+"!"+value));
}

int SortSetSetByTag(object oTgt, string setkey, string dbkey, string sortkey, string value) {
    return StringToInt(SortSetCmd(oTgt,setkey,"SETBYTAG!"+dbkey+"!"+sortkey+"!"+value));
}

int SortSetSetByIdx(object oTgt, string setkey, int index, string sortkey, string value) {
    return StringToInt(SortSetCmd(oTgt,setkey,"SETBYIDX!"+IntToString(index)+"!"+sortkey+"!"+value));
}

string SortSetGetByTag(object oTgt, string setkey, string dbkey) {
    return SortSetCmd(oTgt,setkey,"GETBYTAG!"+dbkey);
}

string SortSetGetByIdx(object oTgt, string setkey, int index) {
    return SortSetCmd(oTgt,setkey,"GETBYIDX!"+IntToString(index));
}

int SortSetRemoveByIdx(object oTgt, string setkey, int index) {
    return StringToInt(SortSetCmd(oTgt,setkey,"REMOVE!"+IntToString(index)));
}

int SortSetDestroy(object oTgt, string setkey) {
    return StringToInt(SortSetCmd(oTgt,setkey,"DESTROY"));
}



