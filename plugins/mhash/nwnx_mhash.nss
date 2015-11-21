/**
 * Generates a UUID.
 *
 * The UUID will be of type v4 when a reliable source of random
 * data is available; otherwise, it will be a v3 bound to your local
 * MAC address.
 *
 * See uuid_generate(3) for details.
 *
 * Returned value is a 36-character UUID like so:
 *   2f8e8c3e-61e0-4f97-b367-b9d5c8123693
 */
string mhash_uuid();

/**
 * Hashes a string with a named algorithm.
 *
 * For a list of supported algorithms, read the mhash manpage of your distro, or have a look
 * into logs.0/nwnx_mhash.txt on the server.
 *
 * Example: mhash_hash("CRC32", "goblin");
 *
 * Returned format is a hex string of variable length (depending on the algorithm).
 *
 * Will return "" on any error, so it is prudent to check for that - especially when hashing
 * sensitive data. Errors are printed to the plugin log.
 */
string mhash_hash(string algorithm, string data);

/**
 * HMACs a string with a given password and named algorithm.
 *
 * For a list of supported algorithms, read the mhash manpage of your distro, or have a look
 * into logs.0/nwnx_mhash.txt on the server.
 *
 * Example: mhash_hmac("SHA256", "sekritpashwurd", "somevalue");
 *
 * Returned format is a hex string of variable length (depending on the algorithm).
 *
 * Will return "" on any error, so it is prudent to check for that - especially when hashing
 * sensitive data. Errors are printed to the plugin log.
 */
string mhash_hmac(string algorithm, string password, string data);

/**
 * Generates a key with the given algorithm, password and salt, using mcrypt.
 *
 * Example: mhash_mcrypt(64, "SHA256", salt", "pass");
 *
 * Length is how long the key should be, a number from 1 to 4096 inclusive.
 *
 * Returned format is a hex string with a length of length * 2.
 *
 * Will return "" on any error, so it is prudent to check for that - especially when hashing
 * sensitive data. Errors are printed to the plugin log.
 */
string mhash_keygen_mcrypt(int length, string algorithm, string password, string salt);

string mhash_uuid()
{
    SetLocalString(GetModule(), "NWNX!MHASH!UUID", " ");
    string ret = GetLocalString(GetModule(), "NWNX!MHASH!UUID");
    // We delete it to make sure we dont leak anything to other scripts.
    DeleteLocalString(GetModule(), "NWNX!MHASH!UUID");
    return ret;
}

string mhash_hash(string algorithm, string data)
{
    SetLocalString(GetModule(), "NWNX!MHASH!HASH", algorithm + "¬" + data);
    string ret = GetLocalString(GetModule(), "NWNX!MHASH!HASH");
    // We delete it to make sure we dont leak anything to other scripts that could read the hash.
    DeleteLocalString(GetModule(), "NWNX!MHASH!HASH");
    return ret;
}

string mhash_hmac(string algorithm, string password, string data)
{
    SetLocalString(GetModule(), "NWNX!MHASH!HMAC", algorithm + "¬" + password + "¬" + data);
    string ret = GetLocalString(GetModule(), "NWNX!MHASH!HMAC");
    // We delete it to make sure we dont leak anything to other scripts that could read the hash.
    DeleteLocalString(GetModule(), "NWNX!MHASH!HMAC");
    return ret;
}

string mhash_keygen_mcrypt(int length, string algorithm, string password, string salt)
{
    SetLocalString(GetModule(), "NWNX!MHASH!KEYGENMCRYPT",
                   algorithm + "¬" + IntToString(length) + "¬" +
                   password + "¬" + salt);
    string ret = GetLocalString(GetModule(), "NWNX!MHASH!KEYGENMCRYPT");
    // We delete it to make sure we dont leak anything to other scripts that could read the hash.
    DeleteLocalString(GetModule(), "NWNX!MHASH!KEYGENMCRYPT");
    return ret;
}
