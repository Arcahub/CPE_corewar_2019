/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_create
*/

#include "cw_asm.h"
#include "header/cw_asm_header.h"
#include <stdlib.h>

cw_asm_t *cw_asm_create(char *path)
{
    cw_asm_t *asm_s = malloc(sizeof(cw_asm_t));

    if (asm_s == NULL)
        return (NULL);
    asm_s->header = cw_asm_header_create();
    asm_s->instructs = NULL;
    asm_s->fdin = cw_asm_input_open(path);
    if (asm_s->header == NULL || asm_s->fdin == NULL) {
        cw_asm_destroy(asm_s);
        return (NULL);
    }
    asm_s->fdout = cw_asm_output_create(path);
    if (asm_s->fdout < 0) {
        cw_asm_destroy(asm_s);
        return (NULL);
    }
    return (asm_s);
}