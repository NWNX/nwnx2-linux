Readme for Resource Manager Plugin

There is no real documentation yet, just some notes:

This plugin makes it possible to load external resources into your running 
server, i.e. resources that are not within your module file. This should be 
extremely helpful for creating new scripts, since you do not need to restart the 
server after a change to the code.

Make sure the resource you are trying to load does not already exist in the 
module, otherwise the Resource Manager will not try to replace it with an 
external version.

How to use it:

1) Copy the [RESOURCEMANAGER] section to your nwnx.ini file and set the SourcePath accordingly.
2) Copy the nwnx.ncs demo script to the 'ncs' directory under the directory specified by SourcePath.
3) Check out the ScriptMod.mod module and read the sign in front of you.
4) The messages you will receive are from the internal and the external script.
5) Try to modify nwnx.nss and compile it with clcompile.exe, while the mod is running!
6) The plugin creates a text file next to the other nwnx log files: nwnx_resman.txt.

Also check out the following forum post for more information:
http://www.nwnx.org/phpBB2/viewtopic.php?t=108

Papillon, 29.05.2005
