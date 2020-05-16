/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Target specific definitions
*/

#ifndef LIBCOREWAR_TARGET_H
#define LIBCOREWAR_TARGET_H

#ifdef MY_TARGET_WASM
    #include "emscripten.h"
    #define CW_EXPORT EMSCRIPTEN_KEEPALIVE
#else
    #define CW_EXPORT
#endif

#endif /* LIBCOREWAR_TARGET_H */
