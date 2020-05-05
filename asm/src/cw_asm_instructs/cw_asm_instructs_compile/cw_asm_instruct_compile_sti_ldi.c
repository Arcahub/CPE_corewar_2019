/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_compile_sti
*/

#include "instructs/cw_asm_instruct.h"

void cw_asm_instruct_compile_sti_ldi(cw_asm_instruct_t *instruct)
{
    for (int i = 0; instruct->parameters[i]; i++) {
        switch (*instruct->parameters[i]) {
        case 'r':
            instruct->coding_byte += 0b01;
            instruct->instruct_size += 1;
            break;
        case DIRECT_CHAR:
            instruct->coding_byte += 0b10;
            instruct->instruct_size += IND_SIZE;
            break;
        default:
            instruct->coding_byte += 0b11;
            instruct->instruct_size += IND_SIZE;
        }
        instruct->coding_byte = instruct->coding_byte << 2;
    }
    instruct->instruct_size += 2;
}