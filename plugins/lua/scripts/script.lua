
--NWNscript Addition and Adjustment
function DelayCommand(t, obj, action, args)
  local scmd = add_token(action, args)
  SetLocalFloat(obj,"relay_delay",t)
  SetLocalString(obj,"relay_cmd",scmd)
  return ExecuteScript("relay_delay",obj)
end

function AssignCommand(obj, action, args)
  local scmd = add_token(action, args)
  SetLocalString(obj,"relay_cmd",scmd)
  return ExecuteScript("relay_assign",obj)
end

function ActionDoCommand(action, args)
  local scmd = add_token(action, args)
  SetLocalString(OBJECT_SELF,"relay_cmd",scmd)
  return ExecuteScript("relay_action",OBJECT_SELF)
end

-- String Function
function string:split(sep)
  local sep, fields = sep or " ", {}
  local pattern = string.format("([^%s]+)", sep)
  self:gsub(pattern, function(c) fields[#fields+1] = c end)
  return fields
end

function string:color(nRed, nGreen, nBlue)
  return string.format("<c%c%c%c>%s</c>", nRed, nGreen, nBlue, self)
end

function string:tolocation()
  local t = self:split()
  if #t < 5 then return end
  local oArea, x, y, z, facing = GetObjectByTag(t[1]), tonumber(t[2]),tonumber(t[3]),tonumber(t[4]),tonumber(t[5])
  if not GetIsObjectValid(oArea) then return end
  return Location(oArea, Vector(x,y,z), facing)
end

--Location Function

-- same function as below but object oriented
function location:tostring()
  if not GetIsObjectValid(self:area()) then return end
  if ((self:x() < 0) or (self:y() < 0)) then return end
  return string.format("%s %.4f %.4f %.4f %.4f", GetTag(self:area()), self:x(), self:y(), self:z(), self:facing())
end

function LocationToString(lLoc)
  local oArea = GetAreaFromLocation(lLoc)
  if not GetIsObjectValid(oArea) then return end
  if ((location.x(lLoc) < 0) or (location.y(lLoc) < 0)) then return end
  return string.format("%s %.4f %.4f %.4f %.4f", GetTag(oArea), location.x(lLoc), location.y(lLoc), location.z(lLoc), location.facing(lLoc))
end

-- Iterators Functions
function first_next_iterator(FirstFunction, NextFunction, CheckFunc, ...)
  local arguments = arg or {}
  local obj, prevobj = FirstFunction(unpack(arguments))
  return function()
    while CheckFunc(obj) do
      prevobj, obj = obj, NextFunction(unpack(arguments))
      return prevobj
    end
  end
end

function GetNearestObjects(nObjectType, oTarget)
  local nNth = 1
  nObjectType = nObjectType or OBJECT_TYPE_ALL
  oTarget = oTarget or OBJECT_SELF
  local obj, prevobj = GetNearestObject(nObjectType, oTarget, nNth)
  return function()
    while GetIsObjectValid(obj) do
      nNth = nNth + 1
      prevobj, obj = obj, GetNearestObject(nObjectType, oTarget, nNth)
      return prevobj
    end
  end
end


--GetNearestCreature(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType,nSecondCriteriaValue,nThirdCriteriaType,nThirdCriteriaValue);
function GetNearestCreatures(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nSecondCriteriaType,nSecondCriteriaValue,nThirdCriteriaType,nThirdCriteriaValue)
  local nNth = 1
  local obj, prevobj = GetNearestCreature(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType,nSecondCriteriaValue,nThirdCriteriaType,nThirdCriteriaValue)
  return function()
    while GetIsObjectValid(obj) do
      nNth = nNth + 1
      prevobj, obj = obj, GetNearestCreature(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType,nSecondCriteriaValue,nThirdCriteriaType,nThirdCriteriaValue)
      return prevobj
    end
  end
end

function GetObjectsByTag(sTag)
  local nNth = 0
  local obj, prevobj = GetObjectByTag(sTag, nNth)
  return function()
    while GetIsObjectValid(obj) do
      nNth = nNth + 1
      prevobj, obj = obj, GetObjectByTag(sTag, nNth)
      return prevobj
    end
  end
end

function GetNearestObjectsByTag(sTag, oObject)
  local nNth = 1
  local obj, prevobj = GetNearestObjectByTag(sTag, oObject, nNth)
  return function()
    while GetIsObjectValid(obj) do
      nNth = nNth + 1
      prevobj, obj = obj, GetNearestObjectByTag(sTag, oObject, nNth)
      return prevobj
    end
  end
end

function ItemsInSlot(oPC)
  local nslot = -1
  return function()
    while (nslot < (NUM_INVENTORY_SLOTS-2)) do
     nslot = nslot + 1
    return nslot, GetItemInSlot(nslot, oPC) 
    end
  end
end

function Effects(oPC) 
  return first_next_iterator(GetFirstEffect, GetNextEffect, GetIsEffectValid, oPC) 
end

function ObjectsInArea(oArea) 
  return first_next_iterator(GetFirstObjectInArea, GetNextObjectInArea, GetIsObjectValid, oArea) 
end

function AllInPersistentObject(oObject, ObjectType)
  return first_next_iterator(GetFirstInPersistentObject, GetNextInPersistentObject, GetIsObjectValid, oObject, ObjectType) 
end

function ItemsInInventory(oTarget)
  return first_next_iterator(GetFirstItemInInventory, GetNextItemInInventory, GetIsObjectValid, oTarget) 
end

function FactionMembers(oMember, bPCOnly)
  return first_next_iterator(GetFirstFactionMember, GetNextFactionMember, GetIsObjectValid, oMember, bPCOnly) 
end

function PCs()
  return first_next_iterator(GetFirstPC, GetNextPC, GetIsObjectValid) 
end

function ItemProperties(oItem)
  return first_next_iterator(GetFirstItemProperty, GetNextItemProperty, GetIsItemPropertyValid, oItem)
end

