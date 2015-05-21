using namespace std;
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#include <map>

#include "mnx.h"

typedef CNWNXBase* (*ClassObject)();

// hashtable (ok, ok, a red-black tree)
map<string, CNWNXBase*> Libraries;

char *GetLogDir()
{
    return ".";
}

void LoadLibraries()
{
    DIR *dp;
    struct dirent *d;
    char *dot, fname[128], logDir[128];
    int i, len;

    CNWNXBase *pBase;
    ClassObject GetClassObject;
    void *handle;

    strcpy(logDir, GetLogDir());

    // search the local directory for all files matching
    // the pattern: 'nwnx_*.so'
    if ((dp = opendir(".")) == NULL) {
        // scream and shout
        cout << "Unable to scan local directory: "
             << strerror(errno)
             << endl;
        return;
    }

    for (d = readdir(dp); d != NULL; d = readdir(dp)) {
        // does it have a '.' ?
        if ((dot = strrchr(d->d_name, '.')) == NULL)
            continue;
        // is the prefix "nwnx_" ?
        if (strncmp("nwnx_", d->d_name, 5) != 0)
            continue;
        // is the suffix ".so" ?
        if (strcmp(".so", dot) != 0)
            continue;

        sprintf(fname, "./%s", d->d_name);

        // load the library
        if ((handle = dlopen(fname, RTLD_NOW)) == NULL) {
            cout << "ERROR: dlopen: " << fname << ": "
                 << dlerror()
                 << endl;
            continue;
        }

        // get the Class Accessor
        if ((GetClassObject = (ClassObject)dlsym(handle,
                              "GetClassObject")) == NULL) {
            cout << "ERROR: dlsym: " << fname << ": "
                 << dlerror()
                 << endl;
            dlclose(handle);
            continue;
        }

        // generate the collection key
        len = dot - &(d->d_name[5]);
        strncpy(fname, &(d->d_name[5]), len);
        fname[len] = 0;
        // upcase it
        for (i = 0; i < len; i++)
            fname[i] = toupper(fname[i]);

        // Access the static instance
        if ((pBase = (*GetClassObject)()) == NULL) {
            cout << "ERROR: " << fname << ": "
                 << "GetClassObject returned NULL"
                 << endl;
            dlclose(handle);
            continue;
        }

        // initialize the plugin
        if (!pBase->OnCreate(logDir)) {
            cout << "ERROR: " << fname << ": "
                 << "OnCreate() failed"
                 << endl;
            dlclose(handle);
            continue;
        }

        // Register the plugin
        Libraries[fname] = pBase;

        cout << "Registered "
             << fname
             << " plugin."
             << endl;
    }

    closedir(dp);
}

FILE *logFile = stdout;

void PayLoad(char *gameObject, char* name, char* value)
{
    int iValueLength;
    int iResultLength;

    if (!name || !value)
        return;

    if (strncmp(name, "NWNX!", 5) != 0) 	// not for us
        return;

    char* library = &name[5];
    if (!library) {
        fprintf(logFile, "* Library not specified.");
        return;
    }

    char* function = strchr(library, '!');
    if (!function) {
        fprintf(logFile, "* Function not specified.");
        return;
    }

    // see if the library is already loaded
    *function = 0x0;
    CNWNXBase* pBase = NULL;
    if (Libraries.find(library) != Libraries.end()) {
        pBase = Libraries[library];
    }
    *function = '!';

    if (pBase != NULL) {
        // library found, handle the request
        iValueLength = strlen(value);
        const char* pRes = pBase->OnRequest(gameObject, function + 1, value);
        if (pRes != NULL) {
            // copy result into nwn variable value while respecting the maximum size
            iResultLength = strlen(pRes);
            if (iValueLength < iResultLength) {
                strncpy(value, pRes, iValueLength);
                *(value + iValueLength) = 0x0;
            } else {
                strncpy(value, pRes, iResultLength);
                *(value + iResultLength) = 0x0;
            }
        }
    } else
        fprintf(logFile, "* Library %s does not exist.", library);
}

int main(int argc, char **argv)
{
    char name[128];
    char buf[1024];
    memset(buf, '.', 1024);

    LoadLibraries();

    strcpy(name, "NWNX!MNX!OPEN!FRED!");
    strcpy(buf, "minstrel:1820");

    PayLoad("me", name, buf);
    cout << endl;

    strcpy(name, "NWNX!MNX!OPEN!WILMA!");
    strcpy(buf, "localhost:2182");
    PayLoad("me", name, buf);
    cout << endl;

    strcpy(name, "NWNX!MNX!SEND!FRED!");
    strcpy(buf, "Bananna");
    PayLoad("me", name, buf);
    cout << endl;

    cout << "Results: " << buf << endl;

    strcpy(name, "NWNX!MNX!SEND!WILMA!");
    strcpy(buf, "Potato");
    PayLoad("me", name, buf);
    cout << endl;

    cout << "Results: " << buf << endl;

    strcpy(name, "NWNX!MNX!SEND!BARNEY!");
    strcpy(buf, "Mud");
    PayLoad("me", name, buf);
    cout << endl;

    cout << "Results: " << buf << endl;


}
