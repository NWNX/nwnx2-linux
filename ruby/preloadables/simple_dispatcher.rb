#  Copyright (C) 2008 Bernhard Stoeckner <elven@swordcoast.net>

#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.

#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.

#  You should have received a copy of the GNU General Public License along
#  with this program; if not, write to the Free Software Foundation, Inc.,
#  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


# This is a very simple dispatcher example
# that serves as an example.

# In your NWN module, just call
#   NWNXRuby_Eval("heartbeat");
# in your module heartbeat script.

# Please be advised that calling NWScript module functions
# from other threads will likely result in stack corruption
# and bitrot.
# For a more advanced example, see threadsafe_dispatcher.rb,
# or just don't use ruby threads. ;)

# Also note that ruby evaluates 0 to TRUE. So blocks like
#  if GetIsObjectValid(OBJECT_INVALID)
#    ..
#  end
# will run regardless.
# Either wrap it, or use
#   if OBJECT_INVALID != pc
# or
#   if 0 != GetIsObjectValid(OBJECT_INVALID)

include NWScript

def heartbeat
  message = "Module heartbeat ran on module " + GetName(GetModule())
  pc = GetFirstPC()
  while (0 != GetIsObjectValid(pc)) do
    SendMessageToPC(pc, message)
    pc = GetNextPC()
  end
  puts message
end
