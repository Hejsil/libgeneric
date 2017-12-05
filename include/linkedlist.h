#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define linkedlist_t(T) struct { void *next; T value; }

void *__linkedlist_make(void *next, void *value, size_t list_struct_size, size_t item_size);
#define linkedlist_make(T, val) ({                                                                   \
    T __value__ = (val);                                                                             \
    __linkedlist_make(NULL, &__value__, sizeof(linkedlist_t(typeof(__value__))), sizeof(__value__)); \
}) 

#define linkedlist_append(list, val) ({                                            \
    typeof(list) __list__ = (list);                                                \
    typeof(__list__->value) __value__ = (val);                                     \
    (void)__list__->next;                                                          \
    __linkedlist_make(__list__, &__value__, sizeof(*__list__), sizeof(__value__)); \
})

#define linkedlist_next(list) (typeof(list))(list)->next

size_t __linkedlist_length(void *vlist);
#define linkedlist_length(list) ({    \
    typeof(list) __list__ = (list);   \
    (void)__list__->next;             \
    (void)__list__->value;            \
    __linkedlist_length(__list__);    \
})

void __linkedlist_free(void *vlist);
#define linkedlist_free(list) do {    \
    typeof(list) __list__ = (list);   \
    (void)__list__->next;             \
    (void)__list__->value;            \
    __linkedlist_free(__list__);      \
} while (0)



#endif // LINKEDLIST_H