#pragma once

#include "internal.h"

#include <typeinfo>
#include <functional>
#include <vector>
#include <algorithm>
#include <cstring>

template <typename... Args>
class Signal : public detail::ServiceSignalBase {
public:
    using function_type = std::function<bool(Args...)>;

private:
    struct Holder {
        Holder(const char* n, function_type&& f)
            : name(n)
            , func(f)
        {}
        const char* name;
        function_type func;
    };

    std::vector<Holder> observers;
    bool abortable_ = false;
    std::function<void()> init_;
    bool inited_ = false;

public:

    /**
     * Constructor: Signal
     *
     * Parameters:
     *
     *     abortable - Optional.  If true the signal can be aborted by an observer.
     *     init - Optional.  A function of type `void()` that does any initialization
     *            necessary.
     *
     */
    // If abortable the signal will stop calling observers if
    // one of them returns true.
    explicit Signal(bool abortable=false, std::function<void()> init = std::function<void()>())
        : detail::ServiceSignalBase(typeid(Signal<Args...>).hash_code())
        , abortable_{abortable}
        , init_{std::move(init)}
    {}

    /**
     * Function: emit
     *
     * Parameters:
     *
     *     args - The arguments that are passed on to observers.
     *
     * Returns:
     *
     *     true if the signal is abortable and an observer returned true,
     *     else the value returned is always false.
     *
     */
    bool emit(Args... args) {
        for(auto& f : observers) {
            if(f.func == nullptr) { continue; }
            bool res = f.func(args...);
            if(res && abortable_) { return res; }
        }
        return false;
    }

    /**
     * Function: connect
     *
     * Connect to a Signal.  If an observer has already connected the function
     * parameter will replace the function the Signal calls.
     *
     * Parameters:
     *
     *     name - A string identifying the observer.
     *     function - A function of type Signal<...>::function_type.
     *
     */
    void connect(const char* name, function_type function) {
        auto it = std::find_if(observers.begin(), observers.end(), [name](const Holder& h) {
            return strcmp(name, h.name) == 0;
        });

        if(it == observers.end()) {
            if (!inited_ && init_ != nullptr) {
                init_();
                inited_ = true;
            }
            observers.emplace_back(name, std::move(function));
        } else {
            it->func = std::move(function);
        }
    }

    /**
     * Function: disconnect
     *
     * Disconnects an observer.
     *
     * Parameters:
     *
     *     name - A string identifying the observer.
     *
     */
    void disconnect(const char* name) {
        auto it = std::find_if(observers.cbegin(), observers.cend(), [name](const Holder& h) {
            return strcmp(name, h.name) == 0;
        });
        if(it != observers.cend()) {
            observers.erase(it);
        }
    }
};
