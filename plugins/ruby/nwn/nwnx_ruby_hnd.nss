#include "nwnx_ruby"

void main()
{
    NWNXRuby_Eval("NWScriptInternal::Scheduler.onCallback()");
}
