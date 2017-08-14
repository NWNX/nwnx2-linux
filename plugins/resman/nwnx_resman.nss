struct CExoKeyTable {
    // 1 when found, 0 when not found, negative on errors
    int exists;
    // the keytable name. for example, CURRENTGAME:modulename
    string name;
};

// Returns the matching CExoKeyTable where the given resref is located.
// This can be used to check if a resref exists within the currently loaded
// game.
struct CExoKeyTable CExoResMan__GetKeyEntry(string resref);

struct CExoKeyTable CExoResMan__GetKeyEntry(string resref)
{
    struct CExoKeyTable ret;
    string key = "NWNX!RESMAN!GetKeyEntry";

    SetLocalString(GetModule(), key, resref);
    string r = GetLocalString(GetModule(), key);
    DeleteLocalString(GetModule(), key);

    if (r != resref) {
        ret.exists = StringToInt(r);
        ret.name = GetSubString(r, FindSubString(r, " ") + 1, 1024 /* pathlen */);
    } else
        ret.exists = 0;

    return ret;
}
