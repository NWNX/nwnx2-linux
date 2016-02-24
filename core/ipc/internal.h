#pragma once

#include <cstdlib>

namespace detail {

class ServiceSignalBase {
    const size_t hash_;
public:
    ServiceSignalBase(size_t hash)
        : hash_(hash)
    {}
    size_t hash() const { return hash_; }

    virtual ~ServiceSignalBase() {}
};

}
