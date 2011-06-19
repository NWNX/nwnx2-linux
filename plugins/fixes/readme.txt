NWNX Fixes 1.0.7

This plugin is intended to provide various fixes and patches to NWServer.

1.0.7 (19.03.2011):
- DoDamage hook that limits HP damage to certain negative limit
- Fix for time freeze that's happening on some servers
- Added hide_charlist_dms and cap_* tweaks

1.0.5 (25.02.2009):
- The plugin is now configurable - an example ini file has been added
- New tweak: ability to set negative HP limit

1.0.4 (14.07.2008):
- New tweak: starting conversation now doesn't unhide a creature
- Updated function signatures for compatibility with 1.69

1.0.3 (22.11.2007):
- Fixed another bug in string comparison code.

1.0.2 (05.11.2007):
- Fixed a bug in string comparison code.

1.0.1 (01.10.2007):
- Another fix for stackable items: OnDisturbed now fires when you try to merge a stack from a placeable with another stack in your inventory. Note: the script fires BEFORE the stack gets merged (usually it fires after that).

1.0 (09.07.2007):
- The engine now takes local variables into account when working with stackable items:
 * Items with different local vars don't stack
 * When you split a stack, all vars get copied
 * When you buy an item marked as infinite from a store, the vars also get copied

---
virusman