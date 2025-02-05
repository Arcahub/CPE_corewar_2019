/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_lfork_write
*/

#include "asm/instructs/cw_asm_instruct.h"
#include "asm/cw_asm_tools.h"
#include <unistd.h>

void cw_asm_instruct_lfork_write(cw_asm_instruct_t *instruct,
        cw_asm_instruct_t **list, bufwriter_t *bw, int *offset)
{
    int value = 0;

    bufwriter_write(bw, &instruct->instruct_code, sizeof(char));
    value = u16_ne_to_be(u32_ne_to_be((
    cw_asm_instruct_write_arg_direct(instruct,
    *list, *offset, 0))));
    bufwriter_write(bw, &value, IND_SIZE);
    *offset -= instruct->instruct_size;
}

