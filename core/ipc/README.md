### Inter Plugin Communicator

#### What is this?

An attempt at creating a somewhat type safe-ish means for plugins to communicate.  That can replace
not only modules.c Service/Event framework but CNWNXBase::ObjectRequest and CNWNXBase::StringRequest as well.

#### Why?

* It's slightly more type safe.
* Service registrants can be any callable c++ type, not just a function pointer.  Same is true of event observers.

#### What are the downsides.

* A bit verbose currently
* Looks more complicated than it is.
* Currently uses RTTI to check types.  Could be moved to a debug mode...

#### Example Signal

For the signal implementer:

**pluginlink.h**

```c++
#include "ipc/Signal.h"
// ...
using EventRunScript = Signal<const char*, nwobjid>;
```

**NWNXWhatever.cpp**
```c++
#include "core/ipc/ipc.h"

EventRunScript* ScriptSignal = nullptr;
bool CNWNXWhatever::OnCreate(gline *config, const char* LogDir)
{
  // ...

  // Create abortable signal.
  ScriptSignal = RegisterSignal(EventRunScript, true);
}

```

**Hooks.cpp**
```c++
void Hook_RunScript(CExoString *script, nwobjid object, int isValidObject) {
  // ...
  // Call all observers
  ScriptSignal->emit(script->Text, object);
  // ...
}
```

For the signal observer:

**NWNXSomeObserver.cpp**

```c++
#include "core/ipc/ipc.h"

static bool do_nothing(const char* script, nwobjid obj) {
  return true; // Abort
}

// Somewhere in plugins loaded event handler...
ConnectSignal(EventRunScript, confKey, do_nothing);
// ...

```

#### Example Service

**pluginlink.h**

```c++
#include "core/ipc/Service.h"
/*
 * Params:
 *  To
 *  Subject
 *  Body
 */
using ServiceSendEmail = Service<const char*, const char*, const char*>;
```

**NWNXEmailSender.cpp**
```c++

#include "core/ipc/ipc.h"

bool CNWNXEmailSender::OnCreate(gline *config, const char* LogDir)
{
  // ...

  // Create abortable signal.
  RegisterService(ServiceSendEmail,
    [this](const char* to, const char* subj, const char* body) {
      this->SomeHowSendEmail(to, subj, body);
    });
}

```

**NWNXSomeServiceUser.cpp**
```c++
#include "core/ipc/ipc.h"

// ...

// Imagine some formatted string in the last parameter.
CallService(ServiceSendEmail,
            "host@someserver.pw",
            "Player Banned",
            "Player Name: xX_badplayer_Xx");
// ...
```
