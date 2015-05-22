#ifndef NWSCRIPT_ADDON_CPP
#define NWSCRIPT_ADDON_CPP

#include <jni.h>
#include "org_nwnx_nwnx2_jvm_NWScript_addon.h"
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

extern jclass jclassNWObject;
extern jmethodID jmethodNWObjectCreate;
extern jmethodID jmethodNWObjectgetOid;

extern jclass jclassNWVector;
extern jmethodID jmethodNWVectorCreate;
extern jmethodID jmethodNWVectorgetX;
extern jmethodID jmethodNWVectorgetY;
extern jmethodID jmethodNWVectorgetZ;

extern jclass jclassNWLocation;
extern jmethodID jmethodNWLocationCreate;
extern jmethodID jmethodNWLocationgetArea;
extern jmethodID jmethodNWLocationgetX;
extern jmethodID jmethodNWLocationgetY;
extern jmethodID jmethodNWLocationgetZ;
extern jmethodID jmethodNWLocationgetFacing;

extern jclass jclassNWEffect;
extern jmethodID jmethodNWEffectCreate;
extern jmethodID jmethodNWEffectgetOid;

extern jclass jclassNWItemProperty;
extern jmethodID jmethodNWItemPropertyCreate;
extern jmethodID jmethodNWItemPropertygetOid;

extern jclass jclassNWNotInContextException;
extern jclass jclassNWInvalidObjectException;
extern jclass jclassNWInvalidEffectException;
extern jclass jclassNWInvalidItemPropertyException;

extern unsigned long nwn_contextDepth;
extern bool j_debugNWScriptCalls;

#define JE(jnienvtok,code) if (jnienvtok->ExceptionCheck()) { jnienvtok->ExceptionDescribe(); jnienvtok->FatalError("while executing native code " #code); }
#define J(jnienvtok,code) jnienvtok->code; JE(jnienvtok,code);

#define iterateFirstNextValid(wrappedClass, getFirstFun, getNextFun, getValidFun, args...) \
	std::vector<jobject> tmp; \
	jobject iter = getFirstFun(env, klass, ## args); \
	while (getValidFun(env, klass, iter)) { \
		tmp.push_back(iter); \
		iter = getNextFun(env, klass, ## args); \
	} \
	jobjectArray ret = J(env, NewObjectArray(tmp.size(), wrappedClass, NULL)); \
	std::vector<jobject>::const_iterator it; int i = 0; \
	for (it = tmp.begin(); it != tmp.end(); ++it) \
		J(env, SetObjectArrayElement(ret, i++, *it)); \
 
JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getPCs(JNIEnv * env, jclass klass)
{
    iterateFirstNextValid(jclassNWObject, Java_org_nwnx_nwnx2_jvm_NWScript_getFirstPC,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getNextPC,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getIsObjectValid);

    return ret;
};

JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getEffects(JNIEnv * env, jclass klass, jobject on)
{
    iterateFirstNextValid(jclassNWEffect, Java_org_nwnx_nwnx2_jvm_NWScript_getFirstEffect,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getNextEffect,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getIsEffectValid, on);
    return ret;
};

JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getItemProperties(JNIEnv * env, jclass klass, jobject on)
{
    iterateFirstNextValid(jclassNWItemProperty, Java_org_nwnx_nwnx2_jvm_NWScript_getFirstItemProperty,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getNextItemProperty,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getIsItemPropertyValid, on);
    return ret;
};

JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getItemsInInventory(JNIEnv * env, jclass klass, jobject on)
{
    iterateFirstNextValid(jclassNWObject, Java_org_nwnx_nwnx2_jvm_NWScript_getFirstItemInInventory,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getNextItemInInventory,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getIsObjectValid, on);
    return ret;
};

JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInArea(JNIEnv * env, jclass klass, jobject on)
{
    iterateFirstNextValid(jclassNWObject, Java_org_nwnx_nwnx2_jvm_NWScript_getFirstObjectInArea,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getNextObjectInArea,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getIsObjectValid, on);
    return ret;
};

JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInShape(JNIEnv * env, jclass klass, jint nShapeType, jfloat fSize, jobject lTarget, jboolean bLineOfSight, jint nObjectFilter, jobject vOrigin)
{
    iterateFirstNextValid(jclassNWObject, Java_org_nwnx_nwnx2_jvm_NWScript_getFirstObjectInShape,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getNextObjectInShape,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getIsObjectValid, nShapeType, fSize, lTarget, bLineOfSight, nObjectFilter, vOrigin);
    return ret;
};

JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getFactionMembers(JNIEnv * env, jclass klass, jobject memberOf, jboolean bPConly)
{
    iterateFirstNextValid(jclassNWObject, Java_org_nwnx_nwnx2_jvm_NWScript_getFirstFactionMember,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getNextFactionMember,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getIsObjectValid, memberOf, bPConly);
    return ret;
};

JNIEXPORT jobjectArray JNICALL Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInPersistentObject(JNIEnv * env, jclass klass, jobject oPersistentObject, jint nResidentObjectType, jint nPersistentZone)
{
    iterateFirstNextValid(jclassNWObject, Java_org_nwnx_nwnx2_jvm_NWScript_getFirstInPersistentObject,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getNextInPersistentObject,
                          Java_org_nwnx_nwnx2_jvm_NWScript_getIsObjectValid, oPersistentObject, nResidentObjectType, nPersistentZone);
    return ret;
};

#endif
