#ifndef SLICE_H
#define SLICE_H

#include <stddef.h>

#define slice_t(type) struct { type *data; size_t length; }

#define slice_make(ptr, length) { .data = (ptr), .length = (length) }

void *__slice_get_ptr(void *vslice, size_t index, size_t item_size);
#define slice_get_ptr(slice, index) ({                                                        \
    typeof((slice)) __slice__ = slice;                                                        \
    __slice__->data;                                                                          \
    __slice__->length;                                                                        \
    (typeof(__slice__->data))__slice_get_ptr(__slice__, (index), sizeof(__slice__->data[0])); \
})

#define slice_get(slice, index)        *slice_get_ptr((slice), (index))
#define slice_set(slice, index, value) *slice_get_ptr((slice), (index)) = (value)

#endif // SLICE_H