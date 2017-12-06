#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include "types.h"

#define __linkedlist_type_check(list) do {             \
    static_assert(is_compatible((list)->next, void *), \
        "List 'next' must be 'void *'");               \
    (void)sizeof((list)->value);                       \
} while (0)

#define linkedlist_t(T) struct { void *next; T value; }

void *__linkedlist_make(void *next, void *value, size_t list_struct_size, size_t item_size);
#define linkedlist_make() NULL

#define linkedlist_append(list, val) ({                                            \
    auto_t __list__ = (list);                                                      \
    typeof(__list__->value) __value__ = (val);                                     \
    __linkedlist_type_check(__list__);                                             \
    __linkedlist_make(__list__, &__value__, sizeof(*__list__), sizeof(__value__)); \
})

#define linkedlist_next(list) (typeof(list))(list)->next

size_t __linkedlist_length(void *vlist);
#define linkedlist_length(list) ({     \
    auto_t __list__ = (list);          \
    __linkedlist_type_check(__list__); \
    __linkedlist_length(__list__);     \
})

void __linkedlist_free(void *vlist);
#define linkedlist_free(list) do {     \
    auto_t __list__ = (list);          \
    __linkedlist_type_check(__list__); \
    __linkedlist_free(__list__);       \
} while (0)



#endif // LINKEDLIST_H