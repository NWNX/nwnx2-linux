void main() {
    object oTarget = GetLocalObject(OBJECT_SELF, "FUNCSEXT_TRANSITION_TARGET");
    if(GetIsObjectValid(oTarget)) {
        SetAreaTransitionBMP(AREA_TRANSITION_RANDOM);
        AssignCommand(GetClickingObject(), JumpToObject(oTarget));
    }
}