#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "arraylist.h"

int arraylist_test() {
    const size_t length = 100;
    arraylist_t(int8_t)  i8_list  = arraylist_make();
    arraylist_t(int16_t) i16_list = arraylist_make();
    arraylist_t(int32_t) i32_list = arraylist_make();
    arraylist_t(int64_t) i64_list = arraylist_make();
    arraylist_t(float)   f_list   = arraylist_make();
    arraylist_t(double)  d_list   = arraylist_make();

    if (i8_list.length  != 0              ||
        i16_list.length != i8_list.length ||
        i32_list.length != i8_list.length ||
        i64_list.length != i8_list.length ||
        f_list.length   != i8_list.length ||
        d_list.length   != i8_list.length) {
        return 1;
    }

    if (i16_list.capacity != i8_list.capacity ||
        i32_list.capacity != i8_list.capacity ||
        i64_list.capacity != i8_list.capacity ||
        f_list.capacity   != i8_list.capacity ||
        d_list.capacity   != i8_list.capacity) {
        return 1;
    }

    for (size_t i = 0; i < length; i++) {
        arraylist_add(&i8_list , i, i);
        arraylist_add(&i16_list, i, i);
        arraylist_add(&i32_list, i, i);
        arraylist_add(&i64_list, i, i);
        arraylist_add(&f_list  , i, i);
        arraylist_add(&d_list  , i, i);
    }

    if (i16_list.length != i8_list.length ||
        i32_list.length != i8_list.length ||
        i64_list.length != i8_list.length ||
        f_list.length   != i8_list.length ||
        d_list.length   != i8_list.length) {
        return 1;
    }

    if (i16_list.capacity != i8_list.capacity ||
        i32_list.capacity != i8_list.capacity ||
        i64_list.capacity != i8_list.capacity ||
        f_list.capacity   != i8_list.capacity ||
        d_list.capacity   != i8_list.capacity) {
        return 1;
    }
    
    for (size_t i = 0; i < length; i++) {
        int8_t  i8  = arraylist_get(&i8_list , i);
        int16_t i16 = arraylist_get(&i16_list, i);
        int32_t i32 = arraylist_get(&i32_list, i);
        int64_t i64 = arraylist_get(&i64_list, i);
        float   f   = arraylist_get(&f_list  , i);
        double  d   = arraylist_get(&d_list  , i);

        if (i8 != i ||
            i16 != i ||
            i32 != i ||
            i64 != i || 
            f   != i ||
            d   != i) {
            return 1;
        }
    }

    for (size_t i = 0; i < length; i++) {
        int8_t  i8  = arraylist_get(&i8_list , 0);
        int16_t i16 = arraylist_get(&i16_list, 0);
        int32_t i32 = arraylist_get(&i32_list, 0);
        int64_t i64 = arraylist_get(&i64_list, 0);
        float   f   = arraylist_get(&f_list  , 0);
        double  d   = arraylist_get(&d_list  , 0);

        arraylist_remove(&i8_list , 0);
        arraylist_remove(&i16_list, 0);
        arraylist_remove(&i32_list, 0);
        arraylist_remove(&i64_list, 0);
        arraylist_remove(&f_list  , 0);
        arraylist_remove(&d_list  , 0);

        if (i8 != i ||
            i16 != i ||
            i32 != i ||
            i64 != i || 
            f   != i ||
            d   != i) {
            return 1;
        }
    }

    arraylist_free(&i8_list);
    arraylist_free(&i16_list);
    arraylist_free(&i32_list);
    arraylist_free(&i64_list);
    arraylist_free(&f_list);
    arraylist_free(&d_list);

    return 0;
}

#define CONCAT(a, b) a ## b
#define CASE(test) if (strcmp(argv[1], #test) == 0) return test()

int main(int argc, char *argv[]) {
    CASE(arraylist_test);

    return 1;
}