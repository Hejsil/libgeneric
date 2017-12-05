#include <stdint.h>
#include <assert.h>
#include <memory.h>

#include "arraylist.h"

void *__arraylist_get_ptr(void *varraylist, size_t index, size_t item_size) {
    arraylist_t(uint8_t) *arraylist = (typeof(arraylist))varraylist;
    assert(index < arraylist->length);
    return &arraylist->data[index * item_size];
}

void __arraylist_add(void *varraylist, size_t index, void *item, size_t item_size) {
    arraylist_t(uint8_t) *arraylist = (typeof(arraylist))varraylist;
    assert(index <= arraylist->length);

    if (arraylist->data == NULL || arraylist->length == arraylist->capacity) {
        arraylist->capacity *= 2;
        arraylist->data = realloc(arraylist->data, arraylist->capacity * item_size);
    }

    size_t byte_index = index * item_size;
    size_t byte_length = arraylist->length * item_size;

    memmove(&arraylist->data[byte_index + item_size], &arraylist->data[byte_index], byte_length - byte_index);
    memcpy(&arraylist->data[byte_index], item, item_size);
    arraylist->length++;
}

void __arraylist_remove(void *varraylist, size_t index, size_t item_size) {
    arraylist_t(uint8_t) *arraylist = (typeof(arraylist))varraylist;
    assert(index < arraylist->length);

    size_t byte_index = index * item_size;
    size_t byte_length = arraylist->length * item_size;

    memmove(&arraylist->data[byte_index], &arraylist->data[byte_index + item_size], (byte_length - byte_index) - item_size);
    arraylist->length--;
}