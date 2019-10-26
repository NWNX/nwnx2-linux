// Name     : hashset
// Purpose  : A general purpose implementation combining a hash and a set
// Author   : Ingmar Stieger
// Modified : April 26, 2003

// return true if hashset sHashSet is valid
int HashSetValid(string sHashSet);

// create a new HashSet on oObject with name sHashSetName
string HashSetCreate(object oObject, string sHashSetName);

// return a "reference" to an existing HashSet on oObject with name sHashSetName
string HashSetGetExistingHashSet(object oObject, string sHashSetName);

// Set key sKey of sHashset to integer value iValue
void HashSetSetLocalInt(string sHashSet, string sKey, int iValue);

// Set key sKey of sHashset to string sValue
void HashSetSetLocalString(string sHashSet, string sKey, string sValue);

// Returns true if sKey is a valid key in sHashSet
int HashSetKeyValid(string sHashSet, string sKey);

// Retrieve integer value of sKey in sHashset
int HashSetGetLocalInt(string sHashSet, string sKey);

// Retrieve string value of sKey in sHashset
string HashSetGetLocalString(string sHashSet, string sKey);

// Clear and delete sHashSet
void HashSetDestroy(string sHashSet);

// Return number of keys in sHashSet
int HashSetGetSize(string sHashSet);

// Return the n-th key in sHashset
// note: this returns the KEY, not the value of the key;
string HashSetGetNthKey(string sHashSet, int iNthKey);

// Return the first key in sHashset
// note: this returns the KEY, not the value of the key;
string HashSetGetFirstKey(string sHashSet);

// Return the next key in sHashset
// note: this returns the KEY, not the value of the key;
string HashSetGetNextKey(string sHashSet);

// Return the current key in sHashset
// note: this returns the KEY, not the value of the key;
string HashSetGetCurrentKey(string sHashSet);

// internal notes:
// The "Index" is used only for the GetNthKey() for performance reasons;
// it is a string that serves as a fixed-size (5 chars) array, i.e. the n-th entry
// of the array is a position (n*5)-5. The entries are stored as hexadecimal
// numbers which point to the n-th key in the "Keys" string (the entries contain
// the position in this string).

// private functions

// return object tag part
object HashSetGetObject(string sHashSet)
{
    int iPos = FindSubString(sHashSet, "#");
    string sTag = GetStringLeft(sHashSet, iPos);
    if (sTag == GetTag(GetModule())) // stupid Bioware BUG!!
        return GetModule();
    else
        return GetObjectByTag(sTag);
}

// return hashset name part
string HashSetGetHashSetName(string sHashSet)
{
    int iPos = FindSubString(sHashSet, "#");
    return GetStringRight(sHashSet, GetStringLength(sHashSet) - iPos - 1);
}

// pad iValue with 0 so that the string is 5 characters long
string CreateIndexPointer5(int iValue)
{
    int i;
    string sPad = "";
    string sValue = IntToString(iValue);
    for (i = 0; i < 5 - GetStringLength(sValue); i++)
        sPad += "0";

    return sPad + sValue;
}

// public functions

int HashSetValid(string sHashSet)
{
    object oHashObject = HashSetGetObject(sHashSet);
    string sHashSetName = HashSetGetHashSetName(sHashSet);

    if (!GetIsObjectValid(oHashObject))
        return FALSE;

    if (GetStringLength(sHashSetName) == 0)
        return FALSE;

    return GetLocalInt(HashSetGetObject(sHashSet), "HashSet#" + HashSetGetHashSetName(sHashSet) + "valid");
}

string HashSetCreate(object oObject, string sHashSetName)
{
    string sHashSet = GetTag(oObject) + "#" + sHashSetName;
    SetLocalInt(oObject, "HashSet#" + sHashSetName + "valid", TRUE);
    SetLocalInt(oObject, "HashSet#" + sHashSetName + "size", 0);
    SetLocalString(oObject, "HashSet#" + sHashSetName + "Keys", "");
    SetLocalString(oObject, "HashSet#" + sHashSetName + "Index", "");
    return sHashSet;
}

string HashSetGetExistingHashSet(object oObject, string sHashSetName)
{
    string sHashSet = GetTag(oObject) + "#" + sHashSetName;

    if (HashSetValid(sHashSet))
        return sHashSet;
    else
        return "";
}

void HashSetSetLocalInt(string sHashSet, string sKey, int iValue)
{
    if (!HashSetValid(sHashSet))
        return;

    object oHashObject = HashSetGetObject(sHashSet);
    string sHashSetName = HashSetGetHashSetName(sHashSet);

    SetLocalInt(oHashObject, "HashSet#" + sHashSetName + "#" + sKey, iValue);

    // Test if key is already in the set
    string sKeys = GetLocalString(oHashObject, "HashSet#" + sHashSetName + "Keys");
    int iPos = FindSubString(sKeys, sKey);
    if (iPos == -1)
    {
        // not found, i.e. new key
        // store location of new key in index array
        string sIndex = GetLocalString(oHashObject, "HashSet#" + sHashSetName + "Index");
        sIndex += CreateIndexPointer5(GetStringLength(sKeys));
        SetLocalString(oHashObject, "HashSet#" + sHashSetName + "Index", sIndex);
        // add new key to keys
        sKeys += sKey + ",";
        SetLocalString(oHashObject, "HashSet#" + sHashSetName + "Keys", sKeys);
        // adjust size variable
        int iSize = GetLocalInt(oHashObject, "HashSet#" + sHashSetName + "size");
        SetLocalInt(oHashObject, "HashSet#" + sHashSetName + "size", iSize + 1);
    }
}

void HashSetSetLocalString(string sHashSet, string sKey, string sValue)
{
    if (!HashSetValid(sHashSet))
        return;

    object oHashObject = HashSetGetObject(sHashSet);
    string sHashSetName = HashSetGetHashSetName(sHashSet);

    SetLocalString(oHashObject, "HashSet#" + sHashSetName + "#" + sKey, sValue);

    // Test if key is already in the set
    string sKeys = GetLocalString(oHashObject, "HashSet#" + sHashSetName + "Keys");
    int iPos = FindSubString(sKeys, sKey);
    if (iPos == -1)
    {
        // not found
        // store location of new key in index array
        string sIndex = GetLocalString(oHashObject, "HashSet#" + sHashSetName + "Index");
        sIndex += CreateIndexPointer5(GetStringLength(sKeys));
        SetLocalString(oHashObject, "HashSet#" + sHashSetName + "Index", sIndex);
        // add new key to keys
        sKeys += sKey + ",";
        SetLocalString(oHashObject, "HashSet#" + sHashSetName + "Keys", sKeys);
        // adjust size variable
        int iSize = GetLocalInt(oHashObject, "HashSet#" + sHashSetName + "size");
        SetLocalInt(oHashObject, "HashSet#" + sHashSetName + "size", iSize + 1);
    }
}

// test if key is valid
int HashSetKeyValid(string sHashSet, string sKey)
{
    string sKeys = GetLocalString(HashSetGetObject(sHashSet), "HashSet#" +
                                     HashSetGetHashSetName(sHashSet) + "Keys");
    int iPos = FindSubString(sKeys, sKey + ",");
    if (iPos != -1)
        return TRUE;
    else
        return FALSE;
}

int HashSetGetLocalInt(string sHashSet, string sKey)
{
    if (!HashSetValid(sHashSet))
        return 0;

    int iResult = 0;
    if (HashSetKeyValid(sHashSet, sKey))
        iResult = GetLocalInt(HashSetGetObject(sHashSet), "HashSet#" +
                              HashSetGetHashSetName(sHashSet) + "#" + sKey);
    return iResult;
}

string HashSetGetLocalString(string sHashSet, string sKey)
{
    if (!HashSetValid(sHashSet))
        return "";

    string sResult = "";
    if (HashSetKeyValid(sHashSet, sKey))
        sResult = GetLocalString(HashSetGetObject(sHashSet), "HashSet#" +
                                 HashSetGetHashSetName(sHashSet) + "#" + sKey);
    return sResult;
}

void HashSetDestroy(string sHashSet)
{
    if (!HashSetValid(sHashSet))
        return;

    object oHashObject = HashSetGetObject(sHashSet);
    string sHashSetName = HashSetGetHashSetName(sHashSet);

    SetLocalInt(oHashObject, "HashSet#" + sHashSetName + "valid", FALSE);
    SetLocalString(oHashObject, "HashSet#" + sHashSetName + "Keys", "");
    SetLocalString(oHashObject, "HashSet#" + sHashSetName + "Index", "");
    SetLocalInt(oHashObject, "HashSet#" + sHashSetName + "size", 0);
    SetLocalInt(oHashObject, "HashSet#" + sHashSetName + "currentKey", 0);
}

int HashSetGetSize(string sHashSet)
{
    if (!HashSetValid(sHashSet))
        return 0;
    return GetLocalInt(HashSetGetObject(sHashSet), "HashSet#" + HashSetGetHashSetName(sHashSet) + "size");
}

string HashSetGetNthKey(string sHashSet, int iNthKey)
{
    if (!HashSetValid(sHashSet))
        return "";

    object oHashObject = HashSetGetObject(sHashSet);
    string sHashSetName = HashSetGetHashSetName(sHashSet);
    string sKeys = GetLocalString(oHashObject, "HashSet#" + sHashSetName + "Keys");
    string sIndex = GetLocalString(oHashObject, "HashSet#" + sHashSetName + "Index");

    if (iNthKey > HashSetGetSize(sHashSet))
        return "";

    // lookup position of n-th key in sKeys
    string sPointer = GetSubString(sIndex, (iNthKey * 5) - 5, 5);
    int iPointer = StringToInt(sPointer);

    // extract key and return it
    string sKey = GetStringRight(sKeys, GetStringLength(sKeys) - iPointer);
    return GetStringLeft(sKey, FindSubString(sKey, ","));
}

string HashSetGetFirstKey(string sHashSet)
{
    if (!HashSetValid(sHashSet))
        return "";

    object oHashObject = HashSetGetObject(sHashSet);
    string sHashSetName = HashSetGetHashSetName(sHashSet);
    SetLocalInt(oHashObject, "HashSet#" + sHashSetName + "currentKey", 1);

    return HashSetGetNthKey(sHashSet, 1);
}

string HashSetGetNextKey(string sHashSet)
{
    if (!HashSetValid(sHashSet))
        return "";

    object oHashObject = HashSetGetObject(sHashSet);
    string sHashSetName = HashSetGetHashSetName(sHashSet);
    int iNextKey = GetLocalInt(oHashObject, "HashSet#" + sHashSetName + "currentKey") + 1;
    SetLocalInt(oHashObject, "HashSet#" + sHashSetName + "currentKey", iNextKey);

    return HashSetGetNthKey(sHashSet, iNextKey);

}

string HashSetGetCurrentKey(string sHashSet)
{
    if (!HashSetValid(sHashSet))
        return "";

    object oHashObject = HashSetGetObject(sHashSet);
    string sHashSetName = HashSetGetHashSetName(sHashSet);
    int iCurrentKey = GetLocalInt(oHashObject, "HashSet#" + sHashSetName + "currentKey");

    return HashSetGetNthKey(sHashSet, iCurrentKey);
}

// internal debugging functions
/*
string HashSetGetAllEntries(string sHashSet)
{
    if (!HashSetValid(sHashSet))
        return "";
    return GetLocalString(HashSetGetObject(sHashSet), "HashSet#" + HashSetGetHashSetName(sHashSet) + "Keys");
}

void HashSetPrint(string sHashSet)
{
    string sKey = HashSetGetFirstKey(sHashSet);
    while (sKey != "")
    {
        SpeakString(sKey + " = " + IntToString(HashSetGetLocalInt(sHashSet, sKey)));
        sKey = HashSetGetNextKey(sHashSet);
    }
}
*/
