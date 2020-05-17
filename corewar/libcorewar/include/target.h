/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Target specific definitions
*/

#ifndef LIBCOREWAR_TARGET_H
#define LIBCOREWAR_TARGET_H

#ifdef MY_TARGET_WASM
    #include "my/types.h"
    #include "my/mem.h"
    #include <emscripten.h>
    #define CW_EXPORT EMSCRIPTEN_KEEPALIVE

    #define CW_EXPORT_TYPE_SIZEOF(name) \
        CW_EXPORT usize_t name##_sizeof(void) \
        { \
            return (sizeof(name##_t)); \
        }

    #define CW_EXPORT_TYPE_CTOR(name) \
        CW_EXPORT name##_t *name##_alloc(usize_t count) \
        { \
            return (my_calloc(count, sizeof(name##_t))); \
        }

    #define CW_EXPORT_TYPE_DTOR(name) \
        CW_EXPORT void name##_free(name##_t *self) \
        { \
            my_free(self); \
        }

    #define CW_EXPORT_TYPE(name) \
        CW_EXPORT_TYPE_SIZEOF(name) \
        CW_EXPORT_TYPE_CTOR(name) \
        CW_EXPORT_TYPE_DTOR(name)

    #define CW_EXPORT_TYPE_SFIELD_SET(name, field, fname, type) \
        CW_EXPORT void name##_set_##fname(name##_t *self, type value) \
        { \
            self->field = value; \
        }

    #define CW_EXPORT_TYPE_SFIELD_GET(name, field, fname, type) \
        CW_EXPORT type name##_get_##fname(name##_t *self) \
        { \
            return (self->field); \
        }

    #define CW_EXPORT_TYPE_SFIELD(name, field, fname, type) \
        CW_EXPORT_TYPE_SFIELD_SET(name, field, fname, type) \
        CW_EXPORT_TYPE_SFIELD_GET(name, field, fname, type)

    #define CW_EXPORT_TYPE_FIELD_SET(name, field, type) \
        CW_EXPORT_TYPE_SFIELD_SET(name, field, field, type)
    #define CW_EXPORT_TYPE_FIELD_GET(name, field, type) \
        CW_EXPORT_TYPE_SFIELD_GET(name, field, field, type)
    #define CW_EXPORT_TYPE_FIELD(name, field, type) \
        CW_EXPORT_TYPE_SFIELD(name, field, field, type)
#else
    #define CW_EXPORT
    #define CW_EXPORT_TYPE_SIZEOF(name)
    #define CW_EXPORT_TYPE_CTOR(name)
    #define CW_EXPORT_TYPE_DTOR(name)
    #define CW_EXPORT_TYPE(name)
    #define CW_EXPORT_TYPE_SFIELD_SET(name, field, fname, type)
    #define CW_EXPORT_TYPE_SFIELD_GET(name, field, fname, type)
    #define CW_EXPORT_TYPE_SFIELD(name, field, fname, type)
    #define CW_EXPORT_TYPE_FIELD_SET(name, field, type)
    #define CW_EXPORT_TYPE_FIELD_GET(name, field, type)
    #define CW_EXPORT_TYPE_FIELD(name, field, type)
#endif

#endif /* LIBCOREWAR_TARGET_H */
