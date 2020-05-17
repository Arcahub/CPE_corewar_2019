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

    #define CW_EXPORT_TYPENAME_SIZEOF(type, name) \
        CW_EXPORT usize_t name##_sizeof(void) \
        { \
            return (sizeof(type)); \
        }

    #define CW_EXPORT_TYPENAME_CTOR(type, name) \
        CW_EXPORT type *name##_alloc(usize_t count) \
        { \
            return (my_calloc(count, sizeof(type))); \
        }

    #define CW_EXPORT_TYPENAME_DTOR(type, name) \
        CW_EXPORT void name##_free(type *self) \
        { \
            my_free(self); \
        }

    #define CW_EXPORT_TYPENAME(type, name) \
        CW_EXPORT_TYPENAME_SIZEOF(type, name) \
        CW_EXPORT_TYPENAME_CTOR(type, name) \
        CW_EXPORT_TYPENAME_DTOR(type, name)

    #define CW_EXPORT_TYPENAME_SFIELD_SET(type, name, field, fname, ftype) \
        CW_EXPORT void name##_set_##fname(type *self, ftype value) \
        { \
            self->field = value; \
        }

    #define CW_EXPORT_TYPENAME_SFIELD_GET(type, name, field, fname, ftype) \
        CW_EXPORT ftype name##_get_##fname(type *self) \
        { \
            return (self->field); \
        }

    #define CW_EXPORT_TYPENAME_SFIELD(type, name, field, fname, ftype) \
        CW_EXPORT_TYPENAME_SFIELD_SET(type, name, field, fname, ftype) \
        CW_EXPORT_TYPENAME_SFIELD_GET(type, name, field, fname, ftype)

    #define CW_EXPORT_TYPENAME_FIELD_SET(type, name, field, ftype) \
        CW_EXPORT_TYPENAME_SFIELD_SET(type, name, field, field, ftype)
    #define CW_EXPORT_TYPENAME_FIELD_GET(type, name, field, ftype) \
        CW_EXPORT_TYPENAME_SFIELD_GET(type, name, field, field, ftype)
    #define CW_EXPORT_TYPENAME_FIELD(type, name, field, ftype) \
        CW_EXPORT_TYPENAME_SFIELD(type, name, field, field, ftype)

    #define CW_EXPORT_TYPE_SIZEOF(name) CW_EXPORT_TYPENAME(name##_t, name)
    #define CW_EXPORT_TYPE_CTOR(name) CW_EXPORT_TYPENAME_CTOR(name##_t, name)
    #define CW_EXPORT_TYPE_DTOR(name) CW_EXPORT_TYPENAME_DTOR(name##_t, name)
    #define CW_EXPORT_TYPE(name) CW_EXPORT_TYPENAME(name##_t, name)
    #define CW_EXPORT_TYPE_SFIELD_SET(name, field, fname, ftype) \
        CW_EXPORT_TYPENAME_SFIELD_SET(name##_t, name, field, fname, ftype)
    #define CW_EXPORT_TYPE_SFIELD_GET(name, field, fname, ftype) \
        CW_EXPORT_TYPENAME_SFIELD_GET(name##_t, name, field, fname, ftype)
    #define CW_EXPORT_TYPE_SFIELD(name, field, fname, ftype) \
        CW_EXPORT_TYPENAME_SFIELD(name##_t, name, field, fname, ftype)
    #define CW_EXPORT_TYPE_FIELD_SET(name, field, ftype) \
        CW_EXPORT_TYPENAME_FIELD_SET(name##_t, name, field, ftype)
    #define CW_EXPORT_TYPE_FIELD_GET(name, field, ftype) \
        CW_EXPORT_TYPENAME_FIELD_GET(name##_t, name, field, ftype)
    #define CW_EXPORT_TYPE_FIELD(name, field, ftype) \
        CW_EXPORT_TYPENAME_FIELD(name##_t, name, field, ftype)
#else
    #define CW_EXPORT
    #define CW_EXPORT_TYPENAME_SIZEOF(type, name)
    #define CW_EXPORT_TYPENAME_CTOR(type, name)
    #define CW_EXPORT_TYPENAME_DTOR(type, name)
    #define CW_EXPORT_TYPENAME(type, name)
    #define CW_EXPORT_TYPENAME_SFIELD_SET(type, name, field, fname, ftype)
    #define CW_EXPORT_TYPENAME_SFIELD_GET(type, name, field, fname, ftype)
    #define CW_EXPORT_TYPENAME_SFIELD(type, name, field, fname, ftype)
    #define CW_EXPORT_TYPENAME_FIELD_SET(type, name, field, ftype)
    #define CW_EXPORT_TYPENAME_FIELD_GET(type, name, field, ftype)
    #define CW_EXPORT_TYPENAME_FIELD(type, name, field, ftype)
    #define CW_EXPORT_TYPE_SIZEOF(name)
    #define CW_EXPORT_TYPE_CTOR(name)
    #define CW_EXPORT_TYPE_DTOR(name)
    #define CW_EXPORT_TYPE(name)
    #define CW_EXPORT_TYPE_SFIELD_SET(name, field, fname, ftype)
    #define CW_EXPORT_TYPE_SFIELD_GET(name, field, fname, ftype)
    #define CW_EXPORT_TYPE_SFIELD(name, field, fname, ftype)
    #define CW_EXPORT_TYPE_FIELD_SET(name, field, ftype)
    #define CW_EXPORT_TYPE_FIELD_GET(name, field, ftype)
    #define CW_EXPORT_TYPE_FIELD(name, field, ftype)
#endif

#endif /* LIBMY_TARGET_H */
