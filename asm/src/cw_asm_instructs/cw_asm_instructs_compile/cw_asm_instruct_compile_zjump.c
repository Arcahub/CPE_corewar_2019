/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_compile_live
*/

#include "instructs/cw_asm_instruct.h"

void cw_asm_instruct_compile_zjump(cw_asm_instruct_t *instruct)
{
    instruct->instruct_size += IND_SIZE;
    instruct->instruct_size += 1;
}