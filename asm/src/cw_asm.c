/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm
*/

#include <stdio.h>
#include "cw_asm.h"
#include "header/cw_asm_header.h"
#include "instructs/cw_asm_instruct.h"

int cw_asm(int argc, char **argv)
{
    cw_asm_t *asm_s = cw_asm_create(argv[1]);
    int ret = 0;

    if (asm_s == NULL)
        return (84);
    cw_asm_header_load(asm_s->header, asm_s->fdin);
    ret = cw_asm_instruct_load(&asm_s->instructs, asm_s->fdin);
    cw_asm_write(asm_s);
    cw_asm_destroy(asm_s);
    return (ret);
}