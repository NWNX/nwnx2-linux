NWWNX Lua plugin
by pardik - 2010
thanks to the work of papillion, virusman, elven and others

Provides a Lua Eval function and an Event function to nwscript, see examples in the scripts dir.
ALL function of the base nwscript are set and defined inside LUA, including function for talent, event and itemproperty functions.
Nwscript functions that return TRUE or FALSE return a boolean value (true, false) inside Lua.

- Eval lua code inside nwscript you can write code like this:
  LuaEvalVoid("ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectBlindness(), GetFirstPC(), 0.0)");
  or:
  LuaEvalVoid("local oPC=GetFirstPC; if GetIsPC(oPC) then SendMessageToPC(oPC, 'Welcome '..GetName(oPC) end)");

- Event function
    ini option: eventListener = "Lua function"
    The event listener accepts two arguments; event (string) and object (number)
    example:
    run_event(event, obj)
    event is a string (ex. 'mod_load'), obj is a number (integer) representing the object calling the event itself.

    Calling event inside NWScript, example:

    void LuaRunEvent(string sEvent, object oSelf=OBJECT_SELF)
    {
        SetLocalString(GetModule(), "NWNX!LUA!EVENT", sEvent+":0x"+ObjectToString(oSelf));
    }
    LuaRunEvent("mod_load", GetModule());
    
    In the preload script provided there are examples of run_event function.

- SCORCO listener
    ini option: sco and rco
    The SCORCO listeners are an rco(key, player) function and an sco(key, player, data) function
    examples in the scripts provided, they are called like these examples:
    --
    Scorco.scorco_proc = function(data)
      data = mysql.escape_string(data)
      DB:query(string.format("REPLACE INTO variables SET value='%s', tag='%s', type='object', name='%s'", data, GetTag(obj), name))
    end
    StoreCampaignObject("LUA", "-", value, obj)
    --
    DB:query(string.format("SELECT value FROM variables WHERE tag='%s' AND type='%s' AND name='%s'", GetTag(obj), otype, name))
    local var = res:fetch_assoc()
    Scorco.scorco_res = var['value']
    RetrieveCampaignObject("LUA", "-", loc, owner, obj)

The following functions: DelayCommand, AssignCommand and ActionDoCommand, are implemented via relay scripts.
They are defined in the example script supplied (in the ./scripts directory)
The three functions above are called via the TOKEN library and the tokenListener function.

Here is an example of a DelayCommand Implementation:

DelayCommand(6.0, oPC, ClearAllActions, {true})- arguments are: 1- time to delay, 2 object, 3 function to be called, 4 arguments of the function as a table

the same for AssignCommand and ActionDoCommand

