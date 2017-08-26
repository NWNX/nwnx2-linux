// Name     : nwnx_odbc.nss
// Purpose  : Hash a NWN object
// Author   : Ingmar Stieger
// Modified : August 4, 2005: Created
// Modified : August 25, 2017 by Tizmo - Factored GetHash() into it's own file.

// This file is licensed under the terms of the
// GNU GENERAL PUBLIC LICENSE (GPL) Version 2

// constant string holding 32 bytes to store the MD5 hash result
const string sHashSpace = "                                ";

// Get the MD5 hash of an object

// The nwnx_mhash module hashes strings, not objects.
// We use the nwnx_odbc module to hash objects since that provides
// direct access to the object stored/retrieved by the SCR/RCO methods.
string GetHash(object oItem);

string GetHash(object oItem) {
	object oModule = GetModule();
	// Store object and hash it
	StoreCampaignObject("NWNX", "HASH", oItem);
	// Copy have value into sHashSpace and save on the module
	SetLocalString(oModule, "NWNX!ODBC!GETHASH", sHashSpace);
	// Read hash value
	return GetLocalString(oModule, "NWNX!ODBC!GETHASH");
}