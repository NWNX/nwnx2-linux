#pragma once

#include "NWNXBase.h"
#include "api/all.h"
#include <jni.h>
#include "org_nwnx_nwnx2_jvm_NWScript.h"
#include "org_nwnx_nwnx2_jvm_NWScript_addon.h"

#include "odmbc/pluginlink.h"
#include "resman/pluginlink.h"

class CNWNXJVM : public CNWNXBase
{
public:
    CNWNXJVM();
    virtual ~CNWNXJVM();

    bool OnCreate(gline *nwnxConfig, const char *LogDir = NULL);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
//	unsigned long OnRequestObject (char *gameObject, char* Request);
    void ExecuteCommand(char *value);
    char *Eval(char *value);


    int nError;

private:

    bool LaunchVM();
    jint registerNWScriptNatives();
    jint registerNWScriptAddonNatives();

    JavaVM *jvm;
    JNIEnv *env;

    jclass cls_initListener;
    jclass cls_eventListener;
    jclass cls_tokenListener;
    jclass cls_nwscript;

    jmethodID jmethodJavaSetup;
    jmethodID jmethodJavaInit;
    jmethodID jmethodJavaShutdown;
    jmethodID jmethodJavaEvent;
    jmethodID jmethodJavaToken;
};
