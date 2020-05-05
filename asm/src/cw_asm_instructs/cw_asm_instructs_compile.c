/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instructs_compile
*/

#include "instructs/cw_asm_instruct.h"
#include "instructs/cw_asm_instruct_compile.h"

void cw_asm_instructs_compile(cw_asm_instruct_t *instructs_list)
{
    cw_asm_instruct_t *instruct = instructs_list;

    for (; instruct; instruct = instruct->next) {
        if (instruct->instruct_code == -1)
            continue;
        CW_ASM_INSTRUCTS_COMPILE_FP[instruct->instruct_code - 1](instruct);
    }
}