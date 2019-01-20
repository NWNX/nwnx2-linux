#include <stdlib.h>

#include "NWNXMHash.h"

extern PLUGINLINK *pluginLink;

#define EMPTYSTRING (char*)calloc(1, sizeof(char))
#define DEBUG 0

// hold MD5 hash result from objhash as a 16 character string (2 x length of MD5 hash + 1 for NULL terminator)
char lastHash[33] = {0};
int WriteSCO(uintptr_t p_ODBCSCORCOEvent);

CNWNXMHash::CNWNXMHash()
{
    confKey = strdup("MHASH");
}

int systemStartup(uintptr_t p)
{
    HANDLE handleRCO = HookEventOptionally(EVENT_ODBC_SCO, WriteSCO);
    if (!handleRCO)
        printf("Cannot hook SCORCO!\n");

    return 0;
}

void CNWNXMHash::bin_to_strhex(unsigned char *bin, size_t binsz, char **result)
{
    char          hex_str[] = "0123456789abcdef";
    unsigned int  i;

    *result = (char *)malloc(binsz * 2 + 1);
    (*result)[binsz * 2] = 0;

    if (!binsz)
        return;

    for (i = 0; i < binsz; i++) {
        (*result)[i * 2 + 0] = hex_str[(bin[i] >> 4) & 0x0F];
        (*result)[i * 2 + 1] = hex_str[(bin[i]) & 0x0F];
    }
}

char *CNWNXMHash::hash(hashid type, const char *input)
{
    MHASH td = mhash_init(type);

    if (td == MHASH_FAILED) {
        Log(0, "Error: mhash_init(%d) returned MHASH_FAILED\n", type);
        return EMPTYSTRING;
    }

    mhash(td, input, strlen(input));

    unsigned char *digest = (unsigned char *) mhash_end(td);

    char *ret;
    bin_to_strhex(digest, mhash_get_block_size(type), &ret);
    free(digest);
    return ret;
}

char *CNWNXMHash::hmac(hashid type, const char *password, const char *input)
{
    if (!mhash_get_hash_pblock(type)) {
        Log(0, "Error: %d does not support HMACs\n", type);
        return EMPTYSTRING;
    }

    MHASH td = mhash_hmac_init(type, (char *) password, strlen(password), mhash_get_hash_pblock(type));

    if (td == MHASH_FAILED) {
        Log(0, "Error: mhash_hmac_init(%d,...) returned MHASH_FAILED\n", type);
        return EMPTYSTRING;
    }

    mhash(td, input, strlen(input));

    unsigned char *digest = (unsigned char *) mhash_hmac_end(td);

    char *ret;
    bin_to_strhex(digest, mhash_get_block_size(type), &ret);
    free(digest);
    return ret;
}

char *CNWNXMHash::keygen(keygenid keygenalg, hashid algorithm, size_t keylen,
                         const char *salt,
                         const char *password)
{
    KEYGEN data;
    data.salt = (void *) salt;
    data.salt_size = strlen(salt);
    data.hash_algorithm[0] = algorithm;
    data.count = 0;

    void *key = malloc(keylen);

    int retv = mhash_keygen_ext(keygenalg, data,
                                key, keylen,
                                (unsigned char *) password, strlen(password));

    char *ret;
    bin_to_strhex((unsigned char *) key, keylen, &ret);
    free(key);
    return ret;
}

hashid CNWNXMHash::find_hashid_by_name(const char *name)
{
    for (size_t i = 0; i < mhash_count(); i++) {
        const unsigned char *n = mhash_get_hash_name_static((hashid) i);

        if (n != NULL && strcmp(name, (const char *) n) == 0)
            return (hashid) i;
    }

    return (hashid) 0xffff;
}

char *CNWNXMHash::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    Log(1, "Request: %s\n", Request);
    Log(2, "Parameters: %s\n", Parameters);

    if (strncmp(Request, "GETOBJHASH", 10) == 0) {
    	Log(2, "* MD5 hash (getobjhash): %s\n", lastHash);
	snprintf(Parameters, 33, "%s", lastHash);
	return Parameters;;
    }

    /* MHASH!HASH algo¬data
     * MHASH!HMAC algo¬pass¬data
     * MHASH!UUID
     */

    if (strcmp("UUID", Request) == 0) {
        uuid_t uuid;
        uuid_generate(uuid);
        char *uuid_s = (char*) malloc(37);
        uuid_unparse_lower(uuid, uuid_s);
        return uuid_s;
    }

    char *p = strdup(Parameters);
    char *algo = strtok(p, "¬");

    if (algo == NULL) {
        Log(0, "Error: algorithm missing in request\n");
        free(p);
        return EMPTYSTRING;
    }

    hashid hid = find_hashid_by_name(algo);

    if (hid == 0xffff) {
        Log(0, "Error: request for unknown algorithm %s\n", algo);
        free(p);
        return EMPTYSTRING;
    }

    if (strncmp(Request, "HASH", 4) == 0) {
        char *data = strtok(NULL, "¬");
        free(p);

        // Allow empty strings as data
        if (data == NULL)
            data = EMPTYSTRING;

        return hash(hid, data);
    }

    if (strncmp(Request, "HMAC", 4) == 0) {
        char *passwd = strtok(NULL, "¬");
        char *data   = strtok(NULL, "¬");
        free(p);

        if ((passwd == NULL || strlen(passwd) == 0)) {
            Log(0, "Error: malformed request, not enough parameters\n");
            return EMPTYSTRING;
        }

        // Allow empty strings as data
        if (data == NULL)
            data = EMPTYSTRING;

        if (mhash_get_hash_pblock(hid) == 0) {
            Log(0, "Error: request HMAC on algorithm that does not support it: %s\n", algo);
            return EMPTYSTRING;
        }

        return hmac(hid, passwd, data);
    }

    if (strncmp(Request, "KEYGENMCRYPT", 12) == 0) {
        char *len = strtok(NULL, "¬");
        char *passwd = strtok(NULL, "¬");
        char *salt   = strtok(NULL, "¬");

        if (len == NULL || (passwd == NULL || strlen(passwd) == 0) || (salt == NULL || strlen(salt) == 0)) {
            Log(0, "Error: malformed request, not enough parameters\n");
            return EMPTYSTRING;
        }

        int ilen = atoi(len);

        if (ilen < 1)
            ilen = 1;

        if (ilen > 4096)
            ilen = 4096;

        return keygen(KEYGEN_MCRYPT, hid, ilen, salt, passwd);
    }

    return NULL;
}

bool CNWNXMHash::OnCreate(gline *nwnxConfig, const char *LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_mhash.txt", LogDir);

    if (!CNWNXBase::OnCreate(nwnxConfig, log))
        return false;

    Log(0, "Supported algorithms:\n");

    for (size_t i = 0; i < mhash_count(); i++) {
        const unsigned char *n = mhash_get_hash_name_static((hashid) i);

        if (n != NULL)
            Log(0, "  %-15s (hmac: %d, result length: %d)\n", n,
                mhash_get_hash_pblock((hashid) i) > 0,
                mhash_get_block_size((hashid) i) * 2
               );
    }

    Log(0, "Supported keygens:\n");

    for (size_t i = 0; i < mhash_keygen_count(); i++) {
        unsigned char *n = mhash_get_keygen_name((keygenid) i);

        if (n != NULL) {
            Log(0, "  %-15s (salt: %d, saltsize: %d, count: %d, maxkeysize: %d, hash: %d)\n", n,
                mhash_keygen_uses_salt((keygenid) i),
                mhash_get_keygen_salt_size((keygenid) i),
                mhash_keygen_uses_count((keygenid) i),
                mhash_get_keygen_max_key_size((keygenid) i),
                mhash_keygen_uses_hash_algorithm((keygenid) i)
               );
            free(n);
        }
    }

    HookEvent(EVENT_CORE_PLUGINSLOADED, systemStartup);

    if (!pluginLink) {
        Log(0, "Plugin link not accessible\n");
        return false;
    } else {
        Log(0, "Plugin link: %08lX\n", pluginLink);
    }

    return true;
}

int WriteSCO(uintptr_t p_ODBCSCORCOEvent)
{
    ODBCSCORCOEvent* s = (ODBCSCORCOEvent*) p_ODBCSCORCOEvent;

    if (DEBUG > 0) {
        printf("DEBUG: MHASH WriteSCO: db='%s', key='%s', player='%s', pData=%08lX, size=%d\n", s->database, s->key, s->player, (unsigned char *)s->pData, s->size);
    }
    if (strncmp("OBJHASH", s->key, 7) == 0) { // compute MD5 hash of the object
        /* Code based on CNWNXMHash::hash() */
        // Hard coding to MD5 as hash type (algorithm)
        hashid type = MHASH_MD5;
        // initialize hashing object
        MHASH td = mhash_init(type);

        if (td == MHASH_FAILED) {
            printf("Error: mhash_init(%d) returned MHASH_FAILED\n", type);
            // return a string of "-1" as the hash
            sprintf(&lastHash[0], "-1");
            return -1;
        }

        // read data into hashing object
        mhash(td, s->pData, s->size);

        // process hash and store result in hash
        unsigned char hash[16] = {0}; // enough size for MD5
        mhash_deinit(td, hash);

        // convert hash to a string and store in lastHash
        for (unsigned int j = 0; j < mhash_get_block_size(type); j += 4) {
            sprintf(&lastHash[j*2], "%.2x%.2x%.2x%.2x", hash[j], hash[j+1], hash[j+2], hash[j+3]);
        }
        if (DEBUG > 0) {
            printf("DEBUG: MD5 hash saved (hash, length): %s, %d\n", lastHash, s->size);
        }
        return 1;
    }

    return 0;
}

