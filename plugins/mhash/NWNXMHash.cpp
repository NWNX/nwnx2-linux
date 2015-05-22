#include <stdlib.h>

#include "NWNXMHash.h"

#define EMPTYSTRING (char*)calloc(1, sizeof(char))

CNWNXMHash::CNWNXMHash()
{
    confKey = strdup("MHASH");
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

    /* MHASH!HASH algo¬data
     * MHASH!HMAC algo¬pass¬data
     */

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

    if (strcmp("HASH", Request) == 0) {
        char *data = strtok(NULL, "¬");
        free(p);

        // Allow empty strings as data
        if (data == NULL)
            data = EMPTYSTRING;

        return hash(hid, data);
    }

    if (strcmp("HMAC", Request) == 0) {
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

    return true;
}
