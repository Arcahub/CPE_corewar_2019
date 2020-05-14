/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_compile_global
*/

#include "instructs/cw_asm_instruct.h"

void cw_asm_instruct_compile_global(cw_asm_instruct_t *instruct)
{
    int i = 0;

    for (; instruct->parameters[i]; i++) {
        switch (*instruct->parameters[i]) {
        case 'r':
            instruct->coding_byte += 0x01;
            instruct->instruct_size += 1;
            break;
        case DIRECT_CHAR:
            instruct->coding_byte += 0x02;
            instruct->instruct_size += DIR_SIZE;
            break;
        default:
            instruct->coding_byte += 0x03;
            instruct->instruct_size += IND_SIZE;
        }
        instruct->coding_byte = instruct->coding_byte << 2;
    }
    instruct->instruct_size += 2;
    for (; i < 3; i++)
        instruct->coding_byte = instruct->coding_byte << 2;
}