#pragma once

#define HAVE_THREADUTIL

#include <future>

class Mainloop
{
public:
    /**
    * A helper to run code inside the gameserver mainloop.
    *
    * Will return a future that you can wait on if you need to interleave
    * with the mainloop. You NEED to do this if you depend on return values
    * captured in the function.
    *
    * Please note that you will deadlock the server when waiting on nested
    * futures. If you wish to run code immediately, it's better to use
    * Now() instead of Next().wait(), which guarantees not to deadlock even
    * when nesting calls.
    *
    * Keep in mind that a running main loop is no guarantee that a module is
    * up and game state accessible.
    *
    * Example:
    *     auto f = Mainloop::Next([&] { printf("I'm in the main loop\n"); });
    *     printf("I'm possibly running before the above.\n");
    *     f.wait();
    *     printf("I'm guaranteed to run after f is done!\n");
    */
    static std::future<void> Next(std::function<void()> f);

    /**
     * Semantically an alias to Next(f).wait(), but will yield immediately
     * if already inside another scheduled function.
     *
     * Deadlock-free.
     *
     * Example:
     *     Mainloop::Now([&] { printf("I'm in the main loop\n"); });
     *     printf("I'm guaranteed to run AFTER the above.\n");
     */
    static void Now(std::function<void()> f);
};
