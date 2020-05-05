/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instructs_compile
*/

#include "instructs/cw_asm_instruct.h"

static void cw_instruct_compile_codingbytes(cw_asm_instruct_t *instruct)
{
    for (int i = 0; instruct->parameters[i]; i++) {
        switch (*instruct->parameters[i]) {
        case 'r':
            instruct->coding_byte += 0b01;
            instruct->instruct_size += 1;
            break;
        case DIRECT_CHAR:
            instruct->coding_byte += 0b10;
            instruct->instruct_size += DIR_SIZE;
            break;
        default:
            instruct->coding_byte += 0b11;
            instruct->instruct_size += IND_SIZE;
        }
        instruct->coding_byte = instruct->coding_byte << 2;
    }
    instruct->instruct_size += 2;
}

static void cw_asm_instruct_compile_size_special_case(cw_asm_instruct_t
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

void cw_asm_instructs_compile(cw_asm_instruct_t *instructs_list)
{
    cw_asm_instruct_t *instruct = instructs_list;

    for (; instruct; instruct = instruct->next) {
        if (instruct->instruct_code == -1 || instruct->instruct_code == 1 ||
        instruct->instruct_code == 9 || instruct->instruct_code == 12 ||
        instruct->instruct_code == 15) {
            cw_asm_instruct_compile_size_special_case(instruct);
            continue;
        }
        cw_instruct_compile_codingbytes(instruct);
    }
}