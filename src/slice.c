#include <stdint.h>
#include <assert.h>

#include "slice.h"

void *__slice_get_ptr(void *vslice, size_t index, size_t item_size) {
    slice_t(uint8_t) *slice = (typeof(slice))vslice;
    assert(index < slice->length);
    return &slice->data[index * item_size];
}