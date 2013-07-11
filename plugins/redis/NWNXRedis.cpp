#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <stdlib.h>

#include "NWNXRedis.h"
#include "HookFunc.h"

extern PLUGINLINK *pluginLink;
extern CNWNXRedis Redis;

CNWNXRedis::CNWNXRedis() {
    confKey = strdup("REDIS");
}

bool CNWNXRedis::OnCreate (gline *config, const char *LogDir) {
    char log[128];

    sprintf(log, "%s/nwnx_redis.txt", LogDir);

    if (!CNWNXBase::OnCreate(config, log))
        return false;

    if(!nwnxConfig->exists(confKey)) {
        Log (0, "o Critical Error: Section [%s] not found in nwnx2.ini\n", confKey);
        return false;
    }

    if (!nwnxConfig->exists(confKey, "pubsubscript")) {
        printf("ERROR: You need to set [REDIS] pubsubscript= in nwnx2.ini\n");
        exit(1);
    }

    char* socket = strdup((char*)((*nwnxConfig)[confKey]["socket"].c_str()));
    char* server = strdup((char*)((*nwnxConfig)[confKey]["server"].c_str()));
    int port = atoi((char*)((*nwnxConfig)[confKey]["port"].c_str()));

    pubsubscript = strdup((char*)((*nwnxConfig)[confKey]["pubsubscript"].c_str()));
    resmanPrefix = strdup((char*)((*nwnxConfig)[confKey]["resmanPrefix"].c_str()));;

    char* password = strdup((char*)((*nwnxConfig)[confKey]["password"].c_str()));
    dbIdx = atoi((char*)((*nwnxConfig)[confKey]["db"].c_str()));

    if (strcmp(socket, "") != 0) {
        context = redisConnectUnix(socket);
        eventContext = redisConnectUnix(socket);
    } else {
        context = redisConnect(server, port);
        eventContext = redisConnect(server, port);
    }

    if (context->err) {
        printf("REDIS: Connection error: %s\n", context->errstr);
        exit(1);
    }
    
    if (eventContext->err) {
        printf("REDIS: Connection error (eventContext): %s\n", eventContext->errstr);
        exit(1);
    }

    if (strcmp(password, "") != 0) {
        freeReplyObject(redisCommand(context, "AUTH %s", password));
        freeReplyObject(redisCommand(eventContext, "AUTH %s", password));
    }

    if (dbIdx > 0) {
        freeReplyObject(redisCommand(context, "SELECT %d", dbIdx));
        freeReplyObject(redisCommand(eventContext, "SELECT %d", dbIdx));
    }

    HookEvent("NWNX/Core/PluginsLoaded", OnPluginsLoaded);
    HookFunctions();

    return true;
}

int CNWNXRedis::OnPluginsLoaded(WPARAM p, LPARAM a) {
    HANDLE handleSCO = HookEvent("NWServer/RCO", ReadSCO);
    HANDLE handleRCO = HookEvent("NWServer/SCO", WriteSCO);
    if (!handleSCO || !handleRCO) {
        printf("o Warning: Cannot hook SCO/RCO because noone provides "
            "NWServer/RCO + /SCO.\n");
    }
    Redis.scorcoEnabled = handleRCO && handleRCO;
    Redis.scorcoQuery = (char*) malloc(1024);

    HANDLE handleRes = HookEvent("NWNX/ResMan/DemandResource", ResManDemandRes);
    if (!handleRes) {
        printf("o Warning: Cannot hook Resman because noone provides "
            "NWNX/ResMan/DemandResource.\n");
    }

    boost::thread ev_thread (redisEventThread);

    return 0;
}

std::vector<char*> argList;

char *CNWNXRedis::OnRequest(char *gameObject, char *Request, char *Parameters) {
    Log(1, "Request: %s\n", Request);

    if (strncmp(Request, "PUSH", 4) == 0) {
        Log(2, "%s: %s\n", Request, Parameters);
        argList.push_back(Parameters);
        return NULL;
    }

    if (strncmp(Request, "CMD", 3) == 0) {
        char* result = NULL;

        Log(1, "%s: %s\n", Request, Parameters);

        const char** arr = (const char**) new char*[argList.size()];
        for(size_t i = 0; i < argList.size(); i++)
            arr[i] = argList[i];

        redisReply *reply = (redisReply*) redisCommandArgv(context,
            argList.size(), arr, NULL);

        if (context->err || NULL == reply) {
            Log(0, "Error: %s\n", reply->str);
            asprintf(&result, "E %d: %s", context->err, context->errstr);

        } else {
            // TYPE strlen(result) RESULT
            // RESULT is
            // - for arrays: strlen(value1) value1 [..]
            // - for strings: strlen(value) value
            // - for integers: 0 value
            // - for errors: strlen(error) error
            // - for nil: // nothing
            switch (reply->type) {
                case REDIS_REPLY_INTEGER: {
                    asprintf(&result, "%d %d %lld", reply->type, 0,
                        reply->integer);
                    break;
                }

                case REDIS_REPLY_ARRAY: {
                    std::string arr;
                    for (size_t i = 0; i < reply->elements; i++) {
                        std::string elem;

                        if (reply->element[i]->type == REDIS_REPLY_INTEGER)
                            elem.append(boost::lexical_cast<std::string>(reply->element[i]->integer));
                        else
                            elem.append(reply->element[i]->str);

                        arr.append(boost::lexical_cast<std::string>(elem.length()));
                        arr.append(" ");
                        arr.append(elem);
                        if (i < reply->elements - 1) arr.append(" ");
                    }

                    asprintf(&result, "%d %d %s", reply->type, arr.length(),
                        arr.c_str());

                    break;
                }

                case REDIS_REPLY_ERROR:
                    Log(0, "Error: %s\n", reply->str);

                case REDIS_REPLY_STRING:
                default:
                    asprintf(&result, "%d %d %s",
                        reply->type, reply->len, reply->str);
                    break;
            }

            freeReplyObject(reply);
        }

        argList.clear();
        Log(2, " => \"%s\"\n", result);
        return result;
    }

    if (strncmp(Request, "PSUBSCRIBE", 10) == 0) {
        redisAppendCommand(eventContext, "PSUBSCRIBE %s", Parameters);
        int done = 0; while (!done) redisBufferWrite(eventContext, &done);
        return NULL;
    }
    if (strncmp(Request, "SUBSCRIBE", 9) == 0) {
        redisAppendCommand(eventContext, "SUBSCRIBE %s", Parameters);
        int done = 0; while (!done) redisBufferWrite(eventContext, &done);
        return NULL;
    }
    if (strncmp(Request, "UNSUBSCRIBE", 11) == 0) {
        redisAppendCommand(eventContext, "UNSUBSCRIBE %s", Parameters);
        int done = 0; while (!done) redisBufferWrite(eventContext, &done);
        return NULL;
    }
    if (strncmp(Request, "PUNSUBSCRIBE", 12) == 0) {
        redisAppendCommand(eventContext, "PUNSUBSCRIBE %s", Parameters);
        int done = 0; while (!done) redisBufferWrite(eventContext, &done);
        return NULL;
    }

    if (strncmp(Request, "GETEVCHAN", 9) == 0) {
        char* result = NULL;
        if (eventsAvailable)
            asprintf(&result, "%s", pubsubEventChannel);
        return result;
    }

    if (strncmp(Request, "GETEVMSG", 8) == 0) {
        char* result = NULL;
        if (eventsAvailable)
            asprintf(&result, "%s", pubsubEventMessage);
        return NULL;
    }


    if (strncmp(Request, "SETSCORCOQUERY", 9) == 0) {
        SetScorcoQuery(Parameters);
        return NULL;
    }

    return NULL;
}

void CNWNXRedis::SetScorcoQuery(char *request) {
    Log (2, "o Got request (scorco): %s\n", scorcoQuery);
    memcpy(scorcoQuery, request, strlen(request) + 1);
}

int CNWNXRedis::WriteSCO(WPARAM p, LPARAM a) {
    SCORCOStruct* s = (SCORCOStruct*) p;
    if (strncmp(s->key, "REDIS", 5) != 0)
        return 0;

    freeReplyObject(redisCommand(Redis.context, Redis.scorcoQuery,
        s->pData, s->size
    ));

    return 1;
}

int CNWNXRedis::ReadSCO(WPARAM p, LPARAM a) {
    SCORCOStruct* s = (SCORCOStruct*) p;
    if (strncmp(s->key, "REDIS", 5) != 0)
        return 0;

    redisReply *reply = (redisReply*)
        redisCommand(Redis.context, Redis.scorcoQuery);

    if (reply->type == REDIS_REPLY_STRING) {
        s->size = reply->len;
        s->pData = (unsigned char*) strdup(reply->str);

    } else {
        Redis.Log(0, "Invalid reply to ReadSCO from database: ");
        Redis.Log(0, "%d %lld %d %s",
            reply->type, reply->integer, reply->len, reply->str);
    }

    freeReplyObject(reply);

    return 1;
}

int CNWNXRedis::ResManDemandRes(WPARAM p, LPARAM a) {
    ResManDemandResStruct* s = (ResManDemandResStruct*) p;

    Redis.Log(2, "Resman: %s\n", s->resref);

    redisReply *reply = (redisReply*)
        redisCommand(Redis.context, "GET %s%s", Redis.resmanPrefix, s->resref);
    if (reply->type == REDIS_REPLY_STRING) {
        s->pData = (unsigned char*) strdup(reply->str);
        s->size = reply->len;
        Redis.Log(1, "Resman: %s -> Sent\n", s->resref);
        return 1;
    }

    return 0;
}

void CNWNXRedis::redisEventThread() {
    void *rvoid;
    while(redisGetReply(Redis.eventContext, &rvoid) == REDIS_OK) {
        redisReply *reply = (redisReply*)rvoid;

        if (
                (reply->elements == 3 &&
                    strncmp(reply->element[0]->str, "message", 7) == 0) ||
                (reply->elements == 4 &&
                    strncmp(reply->element[0]->str, "pmessage", 8) == 0)
            ) {

            // pmessage: "pmessage", mask, channel, message
            // message: "message", channel, message
            if (reply->elements == 4) {
                Redis.pubsubEventChannel = reply->element[2]->str;
                Redis.pubsubEventMessage = reply->element[3]->str;
            } else {
                Redis.pubsubEventChannel = reply->element[1]->str;
                Redis.pubsubEventMessage = reply->element[2]->str;
            }
            Redis.eventsAvailable = true;
            // Wait until it's been eaten
            while (Redis.eventsAvailable) {}

        } else {
            printf("Unhandled event on pubsub context: %d %lld %d %s\n",
                reply->type, reply->integer, reply->len, reply->str);
            for (unsigned int i = 0; i < reply->elements; i++)
                printf("  A %d, %s\n", i, reply->element[i]->str);
        }
        freeReplyObject(reply);
    }
    exit(1);
}
