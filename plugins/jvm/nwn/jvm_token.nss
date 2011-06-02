void call_token(string token, object caller = OBJECT_SELF) {
  SetLocalString(GetModule(), "NWNX!JVM!TOKEN", ObjectToString(caller) + " " + token);
}

void main() {
	string t = GetLocalString(GetModule(), "jvm_token");
    string type = GetLocalString(GetModule(), "jvm_token_type");
    float delay = GetLocalFloat(GetModule(), "jvm_token_delay");

    if ("execute" == type)
        call_token(t, OBJECT_SELF);
    else if ("delay" == type)
        DelayCommand(delay, call_token(t, OBJECT_SELF));
}
