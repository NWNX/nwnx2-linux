/***************************************************************************
    NWNXRuby.cpp - Implementation of the CNWNXRuby class.
    (c) 2008-2013 virusman (virusman@virusman.ru)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include <string.h>
#include <string>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>

#include "NWNXRuby.h"
#include "FunctionHooks.h"
#include "ruby_int.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXRuby::CNWNXRuby()
{
    confKey = "RUBY";
    bHooked = 1;
}

CNWNXRuby::~CNWNXRuby()
{
}

bool CNWNXRuby::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    struct stat statbuf;
    int i = 0;
    sprintf(log, "%s/nwnx_ruby.txt", LogDir);

    // call the base class function
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    Log(0, "NWNX Ruby V.1.1.0\n");
    Log(0, "(c) by virusman, 2008-2013\n");

    RUBY_INIT_STACK;
    ruby_init();
    static char* args[] = { "ruby", "/dev/null" };
    ruby_process_options(2, args);


    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = SIG_DFL;
    sa.sa_flags   = 0;
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGABRT, &sa, NULL);
    sigaction(SIGILL, &sa, NULL);

    ruby_script("embedded");
    ruby_init_loadpath();
    RubyInt_DefineConstants();

    rb_eval_string("puts \"NWNX Ruby Initialized\"\n");

    char *preload = (char*)((*nwnxConfig)[confKey]["preload"].c_str());
    if (strlen(preload) > 0) {
        Log(0, "Preloading: %s\n", preload);
        int error;
        rb_protect((VALUE(*)(VALUE)) rb_require, (VALUE) preload, &error);
        if (error)
            LogRubyError();
    }

    cNWScript = RubyInt_InitNWScript();
    rb_include_module(rb_cObject, cNWScript);

    Log(0, "* Module loaded successfully.\n");

    return true;
}

void CNWNXRuby::LogRubyError()
{
    VALUE lasterr = rb_gv_get("$!");

    // class
    VALUE klass = rb_class_path(CLASS_OF(lasterr));
    Log(2, "* Exception class: %s\n", StringValueCStr(klass));

    // message
    VALUE message = rb_obj_as_string(lasterr);
    Log(2, "* Exception message: %s\n", StringValueCStr(message));
}

void CNWNXRuby::ExecuteCommand(char *value)
{
    //This was for testing purposes
    /*rb_eval_string("nss.PrintInteger(123)");
    rb_eval_string("nss.PrintString(\"123\")");
    rb_eval_string("oModule = nss.GetModule()");
    rb_eval_string("nss.SetLocalInt(oModule, 'ruby', 999)");
    rb_eval_string("puts nss.GetLocalInt(oModule, 'ruby')");*/
}

char *CNWNXRuby::Eval(char *value)
{
    //Evaluate Ruby expression (protected)
    try {
        VALUE retval;
        char *c_retval;
        rb_eval_string("Thread.current[:nwnx_context] = true");
        retval = rb_eval_string_protect(value, &nError);
        rb_eval_string("Thread.current[:nwnx_context] = false");
        if (nError) {
            Log(0, "Error %d while evaluating a Ruby expression: %s\n", nError, value);
            LogRubyError();
            return NULL;
        }
        if (retval != Qnil) {
            if (retval == Qtrue)
                c_retval = "1";
            else if (retval == Qfalse)
                c_retval = "0";
            else {
                retval = rb_funcall(retval, rb_intern("to_s"), 0);
                c_retval = rb_string_value_ptr(&retval);
            }
            if (c_retval) {
                char *buf = (char *) malloc(strlen(c_retval) + 1);
                strcpy(buf, c_retval);
                return buf;
            }
        }
        return NULL;
    } catch (...) {
        Log(0, "Caught a C++ exception while evaluating a Ruby expression: %s\n", value);
        return NULL;
    }
    /*else
    	return RSTRING(rb_cvar_get(cNWScript, rb_intern(RUBY_RETVAL)))->ptr;*/
}

char* CNWNXRuby::OnRequest(char *gameObject, char* Request, char* Parameters)
{
    Log(2, "(S) Request: \"%s\"\n", Request);
    Log(3, "(S) Params:  \"%s\"\n", Parameters);

    if (strncmp(Request, "EXECUTE", 7) == 0) {
        ExecuteCommand(Parameters);
        return NULL;
    } else if (strncmp(Request, "EVAL", 4) == 0) {
        return Eval(Parameters);
    }
    return NULL;
}
/*
unsigned long CNWNXRuby::OnRequestObject (char *gameObject, char* Request)
{
	return OBJECT_INVALID;
}
*/
