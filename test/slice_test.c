#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "slice.h"



int slice_test() {
    const size_t length = 100;
    int8_t  int8s[length];
    int16_t int16s[length];
    int32_t int32s[length];
    int64_t int64s[length];
    float   floats[length];
    double  doubles[length];

    slice_t(int8_t)  slice_int8s   = slice_make(int8s  , length);
    slice_t(int16_t) slice_int16s  = slice_make(int16s , length);
    slice_t(int32_t) slice_int32s  = slice_make(int32s , length);
    slice_t(int64_t) slice_int64s  = slice_make(int64s , length);
    slice_t(float)   slice_floats  = slice_make(floats , length);
    slice_t(double)  slice_doubles = slice_make(doubles, length);

    if (slice_int8s.length   != length ||
        slice_int16s.length  != length ||
        slice_int32s.length  != length ||
        slice_int64s.length  != length ||
        slice_floats.length  != length ||
        slice_doubles.length != length) {
        return 1;
    }

    for (size_t i = 0; i < length; i++) {
        slice_set(&slice_int8s  , i, i);
        slice_set(&slice_int16s , i, i);
        slice_set(&slice_int32s , i, i);
        slice_set(&slice_int64s , i, i);
        slice_set(&slice_floats , i, i);
        slice_set(&slice_doubles, i, i);
    }

    for (size_t i = 0; i < length; i++) {    
        int8_t  i8  = slice_get(&slice_int8s  , i);
        int16_t i16 = slice_get(&slice_int16s , i);
        int32_t i32 = slice_get(&slice_int32s , i);
        int64_t i64 = slice_get(&slice_int64s , i);
        float   f   = slice_get(&slice_floats , i);
        double  d   = slice_get(&slice_doubles, i);

        if (i8  != i ||
            i16 != i ||
            i32 != i ||
            i64 != i || 
            f   != i ||
            d   != i) {
            return 1;
        }
    }

    return 0;
}

#define CONCAT(a, b) a ## b
#define CASE(test) if (strcmp(argv[1], #test) == 0) return test()

int main(int argc, char *argv[]) {
    CASE(slice_test);

    return 1;
}