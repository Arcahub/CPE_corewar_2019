/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_add_write
*/

#include "asm/instructs/cw_asm_instruct.h"
#include <unistd.h>

void cw_asm_instruct_add_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, bufwriter_t *bw, int *offset)
{
    bufwriter_write(bw, &instruct->instruct_code, sizeof(char));
    bufwriter_write(bw, &instruct->coding_byte, sizeof(char));
    cw_asm_instruct_write_args(instruct, list, offset, bw);
    *offset -= instruct->instruct_size;
}