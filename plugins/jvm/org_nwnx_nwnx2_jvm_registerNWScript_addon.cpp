jint CNWNXJVM::registerNWScriptAddonNatives()
{
    JNINativeMethod methods[] = {
        { (char*) "getPCs", (char*) "()[Lorg/nwnx/nwnx2/jvm/NWObject;", (void*) Java_org_nwnx_nwnx2_jvm_NWScript_addon_getPCs },
        { (char*) "getEffects", (char*) "(Lorg/nwnx/nwnx2/jvm/NWObject;)[Lorg/nwnx/nwnx2/jvm/NWEffect;", (void*) Java_org_nwnx_nwnx2_jvm_NWScript_addon_getEffects },
        { (char*) "getItemProperties", (char*) "(Lorg/nwnx/nwnx2/jvm/NWObject;)[Lorg/nwnx/nwnx2/jvm/NWItemProperty;", (void*) Java_org_nwnx_nwnx2_jvm_NWScript_addon_getItemProperties },
        { (char*) "getItemsInInventory", (char*) "(Lorg/nwnx/nwnx2/jvm/NWObject;)[Lorg/nwnx/nwnx2/jvm/NWObject;", (void*) Java_org_nwnx_nwnx2_jvm_NWScript_addon_getItemsInInventory },
        { (char*) "getObjectsInArea", (char*) "(Lorg/nwnx/nwnx2/jvm/NWObject;)[Lorg/nwnx/nwnx2/jvm/NWObject;", (void*) Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInArea },
        { (char*) "getObjectsInShape", (char*) "(IFLorg/nwnx/nwnx2/jvm/NWLocation;ZILorg/nwnx/nwnx2/jvm/NWVector;)[Lorg/nwnx/nwnx2/jvm/NWObject;", (void*) Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInShape },
        { (char*) "getFactionMembers", (char*) "(Lorg/nwnx/nwnx2/jvm/NWObject;Z)[Lorg/nwnx/nwnx2/jvm/NWObject;", (void*) Java_org_nwnx_nwnx2_jvm_NWScript_addon_getFactionMembers },
        { (char*) "getObjectsInPersistentObject", (char*) "(Lorg/nwnx/nwnx2/jvm/NWObject;II)[Lorg/nwnx/nwnx2/jvm/NWObject;", (void*) Java_org_nwnx_nwnx2_jvm_NWScript_addon_getObjectsInPersistentObject },
    };
    return (this->env)->RegisterNatives(this->cls_nwscript, methods, 8);
};
