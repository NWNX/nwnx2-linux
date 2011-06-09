package.path = "./lua/?.lua;./lua/libs/?.lua;./lua/libs/?.lc;./lua/libs/?/init.lua"
package.cpath = "./?.so;./lua/clibs/?.so"

Scorco = {}
Events = {}

function run_event(event, object)
  local ev = Events[event]
  --local x = os.clock()
  if (type(ev) ~= 'table') then return end
  for i,v in ipairs(ev) do
    if (type(v['callback']) == 'function') then v['callback'](object) end
  end
  --logger:debug(string.format("Event: %s on object: 0x%x run time: %d milliseconds", event, tointeger(object), (os.clock()-x)*1000))
end

local scripts = {'constants', 'script'} --add you scripts here better to load them onmoduleload

function loadscripts(oMod)
  for _, v in ipairs(scripts) do 
    --require(v)
    dofile("./lua/"..v..".lua") 
  end
end

function AddListener(Mod, event, callback, priority)
  if not Events[event] then Events[event] = {} end
  local r = {modl = Mod, callback = callback, priority = priority}
  table.insert(Events[event], r)
  table.sort(Events[event], function(a,b) return (a.priority < b.priority) end)  
end

function RemoveListener(Mod)
  for k,v in pairs(Events) do
    --if (type(v) == 'table') then
      for i,n in ipairs(v) do if (n['modl'] == Mod) then table.remove(Events[k], i) end end
    --end
  end
end

function sco(key, player, data)
  if type(Scorco.scorco_proc) ~= 'function' then return end
  local f = Scorco.scorco_proc
  Scorco.scorco_proc = nil
  return f(data)
end

function rco(key, player)
  if not Scorco.scorco_res then return end
  local data = Scorco.scorco_res
  Scorco.scorco_res = nil
  return data
end

Tokens = {current=0}

function call_token(sToken)
  if not sToken then return end
  if Tokens[sToken] ~= nil then
    --local x = os.clock()
    local f, a = Tokens[sToken]["f"], Tokens[sToken]["a"] 
    Tokens[sToken] = nil
    f(unpack(a))
    --logger:debug(string.format("Token: %s run time: %d milliseconds", sToken, (os.clock()-x)*1000))
  end
end

function add_token(action, args)
  Tokens.current = Tokens.current + 1
  if not args then args = {} end
  local scmd = tostring(Tokens.current)
  Tokens[scmd] = {f=action, a=args}
  return scmd
end

AddListener('Events', 'mod_load', loadscripts, 1)
