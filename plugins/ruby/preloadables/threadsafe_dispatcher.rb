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

# This is a threadsafe dispatcher that will proxy all NWScript
# requests through a safe object that will fail if you're in the
# wrong thread.
# 
# This is just a technology example.

Thread.abort_on_exception = true

class NotInContextError < Exception; end

class Dispatcher
  def method_missing(meth, *args)
    fail NotInContextError, "Not in NWNX context while evaluating #{meth.to_s}(#{args.inspect})" unless Thread.current[:nwnx_context] == true
    retval = ::NWScript.method(meth).call(*args)
    puts "  ** Dispatch: #{meth.to_s}(#{args.inspect}) -> #{retval}"
    retval
  end
end

$d = Dispatcher.new

def heartbeat
  message = "Module heartbeat ran on module " + $d.GetName($d.GetModule())
  pc = $d.GetFirstPC()
  while (0 != $d.GetIsObjectValid(pc)) do
    $d.SendMessageToPC(pc, message)
    pc = $d.GetNextPC()
  end

  # This will FAIL.
  Thread.new {
    $d.GetModule()
  }
  puts message
end
