#include <stdlib.h>
#include <memory.h>

#include "linkedlist.h"

void *__linkedlist_make(void *next, void *value, size_t list_struct_size, size_t item_size) {
    linkedlist_t(char) *result = malloc(list_struct_size);
    result->next = next;
    memcpy(&result->value, value, item_size);
    return result;
}

size_t __linkedlist_length(void *vlist) {
    linkedlist_t(char) *list = vlist;
    size_t result = 0;

    while (list != NULL) {
        list = linkedlist_next(list);
        result++;
    }

    return result;
}

void __linkedlist_free(void *vlist) {
    linkedlist_t(char) *list = vlist;
    if (list != NULL) {
        __linkedlist_free(list->next);
        free(list);
    }
}