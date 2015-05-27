#ifndef NWNX_Statsd_H
#define NWNX_Statsd_H

#include "NWNXLib.h"
#include "NWNXBase.h"
#include "statsd_client.h"

#include <unordered_map>
#include <ctime>

using namespace statsd;

class CNWNXStatsd: public CNWNXBase
{
public:
    CNWNXStatsd();
    virtual ~ CNWNXStatsd();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest(char *gameObject, char *Request, char *Parameters);

private:
    StatsdClient link;

    std::unordered_map<std::string, struct timespec> timings;

};

#endif /* NWNX_Statsd_H */
