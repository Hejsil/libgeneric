#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "linkedlist.h"

int linkedlist_test() {
    const size_t length = 100;
    linkedlist_t(int8_t)  *i8_list  = linkedlist_make();
    linkedlist_t(int16_t) *i16_list = linkedlist_make();
    linkedlist_t(int32_t) *i32_list = linkedlist_make();
    linkedlist_t(int64_t) *i64_list = linkedlist_make();
    linkedlist_t(float)   *f_list   = linkedlist_make();
    linkedlist_t(double)  *d_list   = linkedlist_make();

    if (linkedlist_length(i8_list)  != 0 ||
        linkedlist_length(i32_list) != 0 ||
        linkedlist_length(i64_list) != 0 ||
        linkedlist_length(f_list)   != 0 ||
        linkedlist_length(d_list)   != 0) {
        return 1;
    }

    for (size_t i = 0; i < length; i++) {
        i8_list  = linkedlist_append(i8_list,  i);
        i16_list = linkedlist_append(i16_list, i);
        i32_list = linkedlist_append(i32_list, i);
        i64_list = linkedlist_append(i64_list, i);
        f_list   = linkedlist_append(f_list,   i);
        d_list   = linkedlist_append(d_list,   i);
    }

    if (linkedlist_length(i8_list)  != length ||
        linkedlist_length(i32_list) != length ||
        linkedlist_length(i64_list) != length ||
        linkedlist_length(f_list)   != length ||
        linkedlist_length(d_list)   != length) {
        return 1;
    }
    
    auto_t head_i8_list  = i8_list;
    auto_t head_i16_list = i16_list;
    auto_t head_i32_list = i32_list;
    auto_t head_i64_list = i64_list;
    auto_t head_f_list   = f_list;
    auto_t head_d_list   = d_list;

    for (size_t i = 0; i < length; i++) {
        size_t value = length - (i + 1);

        if (i8_list->value  != value          ||
            i16_list->value != i8_list->value ||
            i32_list->value != i8_list->value ||
            i64_list->value != i8_list->value ||
            f_list->value   != i8_list->value ||
            d_list->value   != i8_list->value) {
            return 1;
        }

        i8_list  = linkedlist_next(i8_list);
        i16_list = linkedlist_next(i16_list);
        i32_list = linkedlist_next(i32_list);
        i64_list = linkedlist_next(i64_list);
        f_list   = linkedlist_next(f_list);
        d_list   = linkedlist_next(d_list);
    }

    linkedlist_free(head_i8_list);
    linkedlist_free(head_i16_list);
    linkedlist_free(head_i32_list);
    linkedlist_free(head_i64_list);
    linkedlist_free(head_f_list);
    linkedlist_free(head_d_list);

    return 0;
}

#define CONCAT(a, b) a ## b
#define CASE(test) if (strcmp(argv[1], #test) == 0) return test()

int main(int argc, char *argv[]) {
    CASE(linkedlist_test);

    return 1;
}