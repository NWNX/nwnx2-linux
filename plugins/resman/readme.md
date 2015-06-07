### nwnx_resman

nwnx_resman makes it possible to load external NWN resources into your running
server from a local directory.  This means you can, for example, load resources
that are not in your module, update resources while your server is running.  It can also help debug missing resources.

Additionally it provides NWNX 2.8 event hooks for creating your own resource loaders, see `plugins/resman/pluginlink.h`.

If you choose to use the builtin resource loader it's important to note that its directory structure is as follows:
* Path specified in `nwnx2.ini`
  * [Resource File Extension, e.g 'ncs']
    * [Resource Files]

If you're interested in exploring other resource loaders there are nwnx_redis and nwnx_physfs.

----

#### Existance Event Handlers
The existance event is non-abortable, so returning 1 or 0 has no effect on determing who has the most recent file.  Every resource handler should use something like `exists->mtime = std::max(exists->mtime, (time_t)t)` to play well with other resource handlers.  If you absolutely want to override everyone use `INT_MAX` or something.

 ```c++
 int HandleResourceExistsEvent(uintptr_t p) {
    ResManExistsEvent *exists = reinterpret_cast<ResManExistsEvent*>(p);
    if(PHYSFS_exists(exists->resRefWithExt)) {
        PHYSFS_sint64 t = PHYSFS_getLastModTime(exists->resRefWithExt);
        if (t != -1) {
            exists->mtime = std::max(exists->mtime, (time_t)t);
            exists->exists = true;
        }
    }
    return 0;
}
```

#### Demand Event Handlers
Resource demand handlers should never override and return data unless the last modified time of one of their files is greater than or equal to `ResManDemandEvent::minimum_mtime` :

```c++
int HandleDemandResourceEvent(uintptr_t p)
{
    ResManDemandEvent *event = reinterpret_cast<ResManDemandEvent*>(p);

    // If the file doesn't exist or the minimim required last modified time
    // is greater than what we have, we cannot service this file.
    if (!PHYSFS_exists(event->resref)
        || PHYSFS_getLastModTime(event->resref) == -1
        || event->minimum_mtime > (time_t)PHYSFS_getLastModTime(event->resref)) {
        physfs.Log(4, "Unable to service file: %s, Exists?: %d, Required mtime: %d, Our mtime: %d\n", event->resref, PHYSFS_exists(event->resref),
                   event->minimum_mtime, PHYSFS_getLastModTime(event->resref));
        return 0;
    }
    ...
}
```