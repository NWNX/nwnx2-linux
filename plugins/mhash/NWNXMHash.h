#ifndef NWNX_MHASH_H
#define NWNX_MHASH_H

#include "NWNXLib.h"
#include "NWNXBase.h"

#include <mhash.h>
#include <uuid/uuid.h>

class CNWNXMHash : public CNWNXBase
{
public:
    CNWNXMHash();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);

private:
    hashid find_hashid_by_name(const char *name);
    void bin_to_strhex(unsigned char *bin, size_t binsz, char **result);
    char *hash(hashid type, const char *input);
    char *hmac(hashid type, const char *password, const char *input);
    char *keygen(keygenid keygenalg, hashid algorithm, size_t keylen,
                 const char *salt,
                 const char *password);
};

#endif /* NWNX_MHASH_H */
