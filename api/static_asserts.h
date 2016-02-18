#pragma once

#define static_assert_size(cls,size) \
    static_assert(sizeof(cls) == size, \
        #cls " is not expected size of " #size)

#define static_assert_offset(cls,field,at) \
    static_assert(__builtin_offsetof(cls, field) == at, \
        #cls " member " #field " is not at expected offset " #at)
