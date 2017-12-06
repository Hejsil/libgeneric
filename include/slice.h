#ifndef SLICE_H
#define SLICE_H

#include <stddef.h>
#include <assert.h>

#include "types.h"

#define __slice_type_check(slice) do {                    \
    static_assert(is_compatible((slice)->length, size_t), \
        "Slice 'length' must be 'size_t'");               \
    (void)sizeof((slice)->data);                          \
} while (0)

#define slice_t(T) struct { T *data; size_t length; }

#define slice_make(ptr, length) { .data = (ptr), .length = (length) }

void *__slice_get_ptr(void *vslice, size_t index, size_t item_size);
#define slice_get_ptr(slice, index) ({                                                        \
    auto_t __slice__ = slice;                                                                 \
    __slice_type_check(__slice__);                                                            \
    (typeof(__slice__->data))__slice_get_ptr(__slice__, (index), sizeof(__slice__->data[0])); \
})

#define slice_get(slice, index)        *slice_get_ptr((slice), (index))
#define slice_set(slice, index, value) *slice_get_ptr((slice), (index)) = (value)

#endif // SLICE_H