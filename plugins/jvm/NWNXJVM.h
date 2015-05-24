/***************************************************************************
    NWNXJVM.h - Interface for the CNWNXJVM class.
    (c) 2009 Bernhard Stoeckner (elven@swordcoast.net)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#ifndef NWNXJava_h_
#define NWNXJava_h_

#include "NWNXBase.h"
#include "typedefs.h"
#include "NWNStructures.h"
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


    bool bHooked;
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

#endif
