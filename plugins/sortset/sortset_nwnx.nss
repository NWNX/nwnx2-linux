// Name     : sortset_nwnx.nss
// Purpose  : A general purpose implementation of a sortable set of key/value pairs (NWNX version)
// Author   : John Klar
// Modified : December 18, 2003
// Modified : August 25, 2017 by Tizmo - Added documentation. Cleaned up formatting. 
//            Changed SortSetDestroy from int to void.

// This file is licensed under the terms of the
// GNU GENERAL PUBLIC LICENSE (GPL) Version 2

// Initialize a new sortset
// oTgt: object that will hold the sortset (module, placeable, etc)
// setkey: name of sortset
void SortSetInit(object oTgt, string setkey);

// Deletes the sortset
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
void SortSetDestroy(object oTgt, string setkey);

// Sort the values in a sortset
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
void SortSetSort(object oTgt, string setkey);

// Determine whether a key exists in the sortset
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
// dbkey: key for object in the set (object resref usually)
// Return: True if dbkey exists, else False if dbkey or setkey does not exist
int SortSetExists(object oTgt, string setkey, string dbkey);

// Number of elements in the sortset.
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
// Return: Integer >= 0, -5 if setkey does not exist
int SortSetLength(object oTgt, string setkey);

// Add an element to the sortset
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
// dbkey: key for object in the set (object resref usually)
// sortkey: value used for comparison during sorting
// value: value associated with the key
// Return: 0 if new dbkey/value pair added,
//   -1 if dbkey already exists, -2 if dbkey is NULL,
//   -3 if sortkey is NULL, -4 if value is NULL,
//   -5 if setkey does not exist.
int SortSetAdd(object oTgt, string setkey, string dbkey, string sortkey, string value);

// Set a new value for the dbkey.
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
// dbkey: key for object in the set (object resref usually)
// sortkey: value used for comparison during sorting
// value: value associated with the key
// Return: 0 if new value set for dbkey, -1 if dbkey was not found.
//   -5 if setkey does not exist
int SortSetSetByTag(object oTgt, string setkey, string dbkey, string sortkey, string value);

// Set a new value for the key at index.
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
// index: index of an existing key/value pair in the sortset
// sortkey: value used for comparison during sorting
// value: value associated with the key
// Return: 0 if new value set for dbkey at index,
//   -1 if index out of range,
//   -3 if sortkey is NULL, -4 if value is NULL,
//   -5 if setkey does not exist
int SortSetSetByIdx(object oTgt, string setkey, int index, string sortkey, string value);

// Get value associated with dbkey.
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
// dbkey: key for object in the set (object resref usually)
// Return: value associated with dbkey. NULL if not found, "-5" if setkey does not exist
string SortSetGetByTag(object oTgt, string setkey, string dbkey);

// Get value of key/value pair at index in sortset.
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
// index: index of an existing key/value pair in the sortset
// Return: value of key/value pair. NULL if not found, "-5" if setkey does not exist
string SortSetGetByIdx(object oTgt, string setkey, int index);

// Remove key/value pair at index from sortset.
// oTgt: object that holds the sortset (module, placeable, etc)
// setkey: name of sortset
// index: index of an existing key/value pair in the sortset
// Return: 0 if removed, -1 if index out of range, -5 if setkey does not exist
int SortSetRemoveByIdx(object oTgt, string setkey, int index);


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
    string key = "NWNX!SORTSET!" + setkey;
    SetLocalString(oTgt, key, cmd + "!" + sspad);
    return GetLocalString(oTgt, key);
}

void SortSetInit(object oTgt, string setkey) {
    SortSetCmd(oTgt, setkey, "INIT");
}

void SortSetDestroy(object oTgt, string setkey) {
    SortSetCmd(oTgt, setkey, "DESTROY");
}

void SortSetSort(object oTgt, string setkey) {
    SortSetCmd(oTgt, setkey, "SORT");
}

int SortSetExists(object oTgt, string setkey, string dbkey) {
    return StringToInt(SortSetCmd(oTgt, setkey,"EXISTS!" + dbkey));
}

int SortSetLength(object oTgt, string setkey) {
    return StringToInt(SortSetCmd(oTgt, setkey, "LENGTH"));
}

int SortSetAdd(object oTgt, string setkey, string dbkey, string sortkey, string value) {
    return StringToInt(SortSetCmd(oTgt, setkey, "ADD!" + dbkey + "!" + sortkey + "!" + value));
}

int SortSetSetByTag(object oTgt, string setkey, string dbkey, string sortkey, string value) {
    return StringToInt(SortSetCmd(oTgt, setkey, "SETBYTAG!" + dbkey + "!" + sortkey + "!" + value));
}

int SortSetSetByIdx(object oTgt, string setkey, int index, string sortkey, string value) {
    return StringToInt(SortSetCmd(oTgt, setkey, "SETBYIDX!" + IntToString(index) + "!" + sortkey + "!" + value));
}

string SortSetGetByTag(object oTgt, string setkey, string dbkey) {
    return SortSetCmd(oTgt, setkey, "GETBYTAG!" + dbkey);
}

string SortSetGetByIdx(object oTgt, string setkey, int index) {
    return SortSetCmd(oTgt, setkey, "GETBYIDX!" + IntToString(index));
}

int SortSetRemoveByIdx(object oTgt, string setkey, int index) {
    return StringToInt(SortSetCmd(oTgt, setkey, "REMOVE!" + IntToString(index)));
}
