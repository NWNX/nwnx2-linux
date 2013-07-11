#ifndef NWNX_REDIS_H
#define NWNX_REDIS_H

#include "NWNXBase.h"
#include <hiredis.h>

class CNWNXRedis:public CNWNXBase {
  public:
    CNWNXRedis ();

    bool OnCreate (gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest (char *gameObject, char *Request, char *Parameters);

    void SetScorcoQuery(char* p);

    char* pubsubscript;

    volatile bool  eventsAvailable;
    volatile char* pubsubEventChannel;
    volatile char* pubsubEventMessage;

  private:
    char* resmanPrefix;
    int dbIdx;
    bool scorcoEnabled;
    char* scorcoQuery;

    redisContext *eventContext;
    redisContext *context;

    static int OnPluginsLoaded(WPARAM p, LPARAM a);
    static int ResManDemandRes(WPARAM p, LPARAM a);
    static int ReadSCO(WPARAM p, LPARAM a);
    static int WriteSCO(WPARAM p, LPARAM a);

    static void redisEventThread();
};
#endif /* NWNX_Redis_H */
