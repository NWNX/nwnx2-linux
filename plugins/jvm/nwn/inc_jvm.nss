/*
  This sends event 'ev' to your JVM. Does not return anything.
*/
void JVM_EVENT(string ev, object caller = OBJECT_SELF);


void JVM_EVENT(string ev, object caller = OBJECT_SELF) {
  SetLocalString(GetModule(), "NWNX!JVM!EVENT", ObjectToString(caller) + " " + ev);
}
