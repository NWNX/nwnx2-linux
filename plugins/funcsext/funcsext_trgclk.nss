void main()
{
    object oTarget = GetLocalObject(OBJECT_SELF, "FUNCSEXT_TRANSITION_TARGET");
    if (GetIsObjectValid(oTarget)) {
        object oC = GetClickingObject();
        if (GetIsObjectValid(oC))
            AssignCommand(oC, JumpToObject(oTarget));
    }
}
