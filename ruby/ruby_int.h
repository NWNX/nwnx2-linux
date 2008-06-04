#include "FunctionHooks.h"
#include "ruby/ruby.h"
#include "nwscript.h"

#define RUBY_RETVAL "nwnx_retval"

#define OBJECT_INVALID 0x7F000000
//temporary
#define OBJECT_SELF 0x7F000000

#ifdef __cplusplus
extern "C" {
#endif

VALUE RubyInt_InitNWScript();
void RubyInt_DefineConstants();


#ifdef __cplusplus
}
#endif

