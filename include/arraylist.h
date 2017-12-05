#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>
#include <stdlib.h>

#define arraylist_t(type) struct { type *data; size_t length, capacity; }

#define arraylist_make() { .data = NULL, .length = 0, .capacity = 1 }

void *__arraylist_get_ptr(void *varraylist, size_t index, size_t item_size);
#define arraylist_get_ptr(arraylist, index) ({                                                                \
    typeof((arraylist)) __arraylist__ = (arraylist);                                                          \
    (void)__arraylist__->length;                                                                              \
    (void)__arraylist__->capacity;                                                                            \
    (typeof(__arraylist__->data))__arraylist_get_ptr(__arraylist__, (index), sizeof(__arraylist__->data[0])); \
})

#define arraylist_get(arraylist, index)        *arraylist_get_ptr((arraylist), (index))
#define arraylist_set(arraylist, index, value) *arraylist_get_ptr((arraylist), (index)) = (value)

void __arraylist_add(void *varraylist, size_t index, void *item, size_t item_size);
#define arraylist_add(arraylist, index, item) {                                         \
    typeof((arraylist)) __arraylist__ = (arraylist);                                    \
    typeof(__arraylist__->data[0]) __item__ = item;                                     \
    (void)__arraylist__->length;                                                        \
    (void)__arraylist__->capacity;                                                      \
    __arraylist_add(__arraylist__, (index), &__item__, sizeof(__arraylist__->data[0])); \
} while (0)

void __arraylist_remove(void *varraylist, size_t index, size_t item_size);
#define arraylist_remove(arraylist, index) do {                                 \
    typeof((arraylist)) __arraylist__ = (arraylist);                            \
    (void)__arraylist__->length;                                                \
    (void)__arraylist__->capacity;                                              \
    __arraylist_remove(__arraylist__, (index), sizeof(__arraylist__->data[0])); \
} while (0)

#define arraylist_free(arraylist) do {               \
    typeof((arraylist)) __arraylist__ = (arraylist); \
    (void)__arraylist__->length;                     \
    (void)__arraylist__->capacity;                   \
    free(__arraylist__->data);                       \
} while (0)

#endif // ARRAYLIST_H