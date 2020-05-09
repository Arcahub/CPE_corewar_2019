/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_instruct_live_write
*/

#include "asm/instructs/cw_asm_instruct.h"
#include <unistd.h>

void cw_asm_instruct_live_write(cw_asm_instruct_t *instruct,
cw_asm_instruct_t **list, int fdout, int *offset)
{
    write(fdout, &instruct->instruct_code, sizeof(char));
    cw_asm_instruct_write_args(instruct, list, offset, fdout);
    *offset -= instruct->instruct_size;
}