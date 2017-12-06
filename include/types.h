#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include <stdint.h>

typedef enum typeid_e {
    TYPEID_VOIDPTR,
    TYPEID_INT8,
    TYPEID_INT16,
    TYPEID_INT32,
    TYPEID_INT64,
    TYPEID_UINT8,
    TYPEID_UINT16,
    TYPEID_UINT32,
    TYPEID_UINT64,
    TYPEID_FLOAT,
    TYPEID_DOUBLE,
    TYPEID_OTHER
} typeid_t;

#define auto_t __auto_type

#define is_compatible(x, T) _Generic((x), T: true, default: false)

#define get_typeid(T)             \
    _Generic((T),                 \
        void *  : TYPEID_VOIDPTR, \
        int8_t  : TYPEID_INT8,    \
        int16_t : TYPEID_INT16,   \
        int32_t : TYPEID_INT32,   \
        int64_t : TYPEID_INT64,   \
        uint8_t : TYPEID_UINT8,   \
        uint16_t: TYPEID_UINT16,  \
        uint32_t: TYPEID_UINT32,  \
        uint64_t: TYPEID_UINT64,  \
        float   : TYPEID_FLOAT,   \
        double  : TYPEID_DOUBLE,  \
        default : TYPEID_OTHER    \
)

#endif // TYPES_H