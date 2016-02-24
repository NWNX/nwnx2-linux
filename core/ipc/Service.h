#pragma once

#include "internal.h"
#include <functional>

template <typename... Args>
struct Service : public detail::ServiceSignalBase {
    using function_type = std::function<void(Args...)>;
    function_type func;

    /**
     * Constructor: Service
     *
     * Parameter:
     *
     *     function - A function of type Service<...>::function_type.
     *
     */
    explicit Service(function_type function)
        : detail::ServiceSignalBase(typeid(Service<Args...>).hash_code())
        , func{std::move(function)}
    {}

    /**
     * Function: Call
     *
     * Calls the internal std::function<void(Args...)>.
     *
     */
    void Call(Args... args) {
        if(func == nullptr) { return; }
        func(args...);
    }

    /**
     * Function: SetFunction
     *
     * Sets the interal std::function.  This is not particularly useful
     * unless a plugin reloading framework was developed.
     *
     * Parameter:
     *
     *     func - A function of type Service<...>:function_type.
     *
     */
    void SetFunction(function_type func) {
        func = std::move(func);
    }
};
