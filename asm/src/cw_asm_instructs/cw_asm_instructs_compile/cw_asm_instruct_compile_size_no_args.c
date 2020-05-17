/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_compile_no_args
*/

#include "cw_asm.h"
#include "instructs/cw_asm_instruct.h"

void cw_asm_instruct_compile_size_no_args(cw_asm_instruct_t
*instruct)
{
    if (instruct->instruct_code == -1)
        return;
    if (*instruct->parameters[0] == '%') {
        instruct->instruct_size += DIR_SIZE;
    } else
        instruct->instruct_size += IND_SIZE;
    instruct->instruct_size += 1;
}