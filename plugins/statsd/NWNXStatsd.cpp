#include "NWNXStatsd.h"

CNWNXStatsd::CNWNXStatsd()
{
    confKey = strdup("STATSD");
}

CNWNXStatsd::~CNWNXStatsd()
{
}

bool CNWNXStatsd::OnCreate(gline *config, const char *LogDir)
{
    char log[128];

    sprintf(log, "%s/nwnx_statsd.txt", LogDir);

    if (!CNWNXBase::OnCreate(config, log))
        return false;

    if (!nwnxConfig->exists(confKey) ||
            !nwnxConfig->exists(confKey, "host") ||
            !nwnxConfig->exists(confKey, "port") ||
            !nwnxConfig->exists(confKey, "prefix")) {

        printf("STATSD requires the following config keys: host, port, prefix\n");
        exit(1);
    }

    link = StatsdClient((*nwnxConfig)[confKey]["host"].c_str(),
                        atoi((*nwnxConfig)[confKey]["port"].c_str()),
                        (*nwnxConfig)[confKey]["prefix"].c_str());

    return true;
}

int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
    return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}

char *CNWNXStatsd::OnRequest(char *gameObject, char *Request, char *Parameters)
{
    const struct StatsdStrCommand_s *cmd;

    Log(1, "Req: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    if (0 == strcmp(Request, "INC")) {
        link.inc(Parameters);
        return NULL;
    }

    if (0 == strcmp(Request, "DEC")) {
        link.dec(Parameters);
        return NULL;
    }

    if (0 == strcmp(Request, "GAUGE")) {
        char *pp = strdup(Parameters);
        char *stat = strtok(pp, " ");
        size_t val = atoi(strtok(NULL, " "));
        link.gauge(stat, val);
        free(pp);
        return NULL;
    }

    if (0 == strcmp(Request, "COUNT")) {
        char *pp = strdup(Parameters);
        char *stat = strtok(pp, " ");
        size_t val = atoi(strtok(NULL, " "));
        link.count(stat, val);
        free(pp);
        return NULL;
    }

    if (0 == strcmp(Request, "TIMING")) {
        char *pp = strdup(Parameters);
        char *stat = strtok(pp, " ");
        size_t val = atoi(strtok(NULL, " "));
        link.timing(stat, val);
        free(pp);
        return NULL;
    }

    if (0 == strcmp(Request, "START")) {
        struct timespec start;
        clock_gettime(CLOCK_MONOTONIC, &start);

        timings[std::string(Parameters)] = start;

        return NULL;
    }

    if (0 == strcmp(Request, "STOP")) {
        std::unordered_map<std::string, struct timespec>::iterator iter =
            timings.find(std::string(Parameters));

        if (iter != timings.end()) {
            struct timespec end;
            clock_gettime(CLOCK_MONOTONIC, &end);

            int64_t diff = timespecDiff(&end, &iter->second) / 1000;

            link.timing(Parameters, diff);

            timings.erase(iter);

        } else {
            printf("ERROR: STOP without START on key %s\n", Parameters);
            Log(0, "ERROR: STOP without START on key %s\n", Parameters);
        }

        return NULL;
    }

    return NULL;
}
