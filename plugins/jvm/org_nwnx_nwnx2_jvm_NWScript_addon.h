#ifndef NWSCRIPT_ADDON_H
#define NWSCRIPT_ADDON_H
#include <jni.h>

#include "api/all.h"
#include "org_nwnx_nwnx2_jvm_NWScript.h"
#include <iostream>

extern "C" {
    JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getPCs(JNIEnv *, jclass);
    JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getEffects(JNIEnv *, jclass, jobject);
    JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getItemProperties(JNIEnv *, jclass, jobject);
    JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getItemsInInventory(JNIEnv *, jclass, jobject);
    JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInArea(JNIEnv *, jclass, jobject);
    JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInShape(JNIEnv *, jclass, jint, jfloat, jobject, jboolean, jint, jobject);
    JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getFactionMembers(JNIEnv *, jclass, jobject, jboolean);
    JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInPersistentObject(JNIEnv *, jclass, jobject, jint, jint);
};
#endif
