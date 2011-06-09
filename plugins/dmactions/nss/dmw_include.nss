/* DM Wand Helper
 *
 * 2010 by pZv!
 */

/* Example multiselect action script
void main() {
    struct dmwTarget dmwTarget = dmwGetTarget();

    while(dmwTarget.o != OBJECT_INVALID) {
        SetCommandable(FALSE, dmwTarget.o);
        dmwTarget = dmwGetNextTarget(dmwTarget);
    }
}
*/

 struct dmwTarget {
    object dm;
    object o;
    location l;
    int p;
    int c;
    int dms;
    int pcs;
};

// Set single target
void dmwSetTargetObject(object oTarget, object oDM = OBJECT_SELF);

// Set targeted location
void dmwSetTargetLocation(location lTarget, object oDM = OBJECT_SELF);

// Get single/first target
struct dmwTarget dmwGetTarget(object oDM = OBJECT_SELF);

// Get next target
struct dmwTarget dmwGetNextTarget(struct dmwTarget TargetStruct);

// Get targets number
int dmwGetMultiTargetsCount(object oDM);

// Clear multi target list
void dmwClearAllMultiTargets(object oDM);

// Add target to list
void dmwAddMultiTarget(object oDM, object oTarget);

// Get nNth target from list
object dmwGetMultiTarget(object oDM, int nNth=0);


void dmwSetTargetObject(object oTarget, object oDM = OBJECT_SELF) {
    dmwClearAllMultiTargets(oDM);
    dmwAddMultiTarget(oDM, oTarget);
}

void dmwSetTargetLocation(location lTarget, object oDM = OBJECT_SELF) {
    SetLocalLocation(oDM, "dmw.lTarget", lTarget);
}

struct dmwTarget dmwGetTarget(object oDM = OBJECT_SELF) {
    struct dmwTarget TargetStruct;
    TargetStruct.dm = oDM;
    TargetStruct.o = dmwGetMultiTarget(oDM);
    TargetStruct.l = GetLocalLocation(oDM, "dmw.lTarget");
    TargetStruct.p = 0;
    TargetStruct.c = dmwGetMultiTargetsCount(oDM);
    TargetStruct.pcs = GetLocalInt(oDM, "dmw.PCs_InTargets");
    TargetStruct.dms = GetLocalInt(oDM, "dmw.DMs_InTargets");
    return TargetStruct;
}

struct dmwTarget dmwGetNextTarget(struct dmwTarget TargetStruct) {
    TargetStruct.o = dmwGetMultiTarget(TargetStruct.dm, ++TargetStruct.p);

    return TargetStruct;
}

int dmwGetMultiTargetsCount(object oDM) {
    return GetLocalInt(oDM, "dmw.MultiTargets");
}

void dmwClearAllMultiTargets(object oDM) {
    int nCount = dmwGetMultiTargetsCount(oDM);
    SetLocalInt(oDM, "dmw.MultiTargets", 0);
    SetLocalInt(oDM, "dmw.PCs_InTargets", 0);
    SetLocalInt(oDM, "dmw.DMs_InTargets", 0);
    DeleteLocalLocation(oDM, "dmw.lTarget");

    int i;
    for(i=0; i < nCount; ++i) {
        DeleteLocalObject(oDM, "dmw.MultiTarget_"+IntToString(i));
    }
}

void dmwAddMultiTarget(object oDM, object oTarget) {
    int nCount = dmwGetMultiTargetsCount(oDM);
    if(nCount == 0 && GetAreaFromLocation(GetLocalLocation(oDM, "dmw.lTarget")) == OBJECT_INVALID) {
        dmwSetTargetLocation(GetLocation(oTarget), oDM);
    }

    SetLocalObject(oDM, "dmw.MultiTarget_"+IntToString(nCount++), oTarget);
    SetLocalInt(oDM, "dmw.MultiTargets", nCount);

    if(GetIsPC(oTarget) && (!GetIsDM(oTarget)) && (!GetIsDMPossessed(oTarget))) {
        SetLocalInt(oDM, "dmw.PCs_InTargets", GetLocalInt(oDM, "dmw.PCs_InTargets") + 1);
    } else
    if(GetIsDM(oTarget)) {
        SetLocalInt(oDM, "dmw.DMs_InTargets", GetLocalInt(oDM, "dmw.DMs_InTargets") + 1);
    }
}

object dmwGetMultiTarget(object oDM, int nNth=0) {
    int nCount = dmwGetMultiTargetsCount(oDM);

    if(nNth < nCount) {
        return GetLocalObject(oDM, "dmw.MultiTarget_"+IntToString(nNth));
    }

    return OBJECT_INVALID;
}
