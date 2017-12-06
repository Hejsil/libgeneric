#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

#include "types.h"

#define __arraylist_type_check(list) do {                  \
    static_assert(is_compatible((list)->length, size_t),   \
        "List 'length' must be 'size_t'");                 \
    static_assert(is_compatible((list)->capacity, size_t), \
        "List 'capacity' must be 'size_t'");               \
    (void)sizeof((list)->data);                            \
} while (0)


#define arraylist_t(T) struct { T *data; size_t length, capacity; }

#define arraylist_make() { .data = NULL, .length = 0, .capacity = 1 }

void *__arraylist_get_ptr(void *varraylist, size_t index, size_t item_size);
#define arraylist_get_ptr(arraylist, index) ({                                                                \
    typeof((arraylist)) __arraylist__ = (arraylist);                                                          \
    __arraylist_type_check(__arraylist__);                                                                    \
    (typeof(__arraylist__->data))__arraylist_get_ptr(__arraylist__, (index), sizeof(__arraylist__->data[0])); \
})

#define arraylist_get(arraylist, index)        *arraylist_get_ptr((arraylist), (index))
#define arraylist_set(arraylist, index, value) *arraylist_get_ptr((arraylist), (index)) = (value)

void __arraylist_add(void *varraylist, size_t index, void *item, size_t item_size);
#define arraylist_add(arraylist, index, item) {                                         \
    typeof((arraylist)) __arraylist__ = (arraylist);                                    \
    typeof(__arraylist__->data[0]) __item__ = (item);                                   \
    __arraylist_type_check(__arraylist__);                                              \
    __arraylist_add(__arraylist__, (index), &__item__, sizeof(__arraylist__->data[0])); \
} while (0)

void __arraylist_remove(void *varraylist, size_t index, size_t item_size);
#define arraylist_remove(arraylist, index) do {                                 \
    typeof((arraylist)) __arraylist__ = (arraylist);                            \
    __arraylist_type_check(__arraylist__);                                      \
    __arraylist_remove(__arraylist__, (index), sizeof(__arraylist__->data[0])); \
} while (0)

#define arraylist_free(arraylist) do {               \
    typeof((arraylist)) __arraylist__ = (arraylist); \
    __arraylist_type_check(__arraylist__);           \
    free(__arraylist__->data);                       \
} while (0)

#endif // ARRAYLIST_H